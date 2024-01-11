#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_SIZE 256
#define PI 3.14159265358979323846

typedef struct {
    double real;
    double imag;
} Complex;

Complex multiply(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex add(Complex a, Complex b);
Complex cexp(double phi);
void FFT(Complex signal[], int n, int step);
void IFFT(Complex signal[], int n);
void shiftFFT(Complex *data, int width, int height);

// 신호 중심 이동 함수
void centerShift(Complex *data) {
    for (int m = 0; m < IMG_SIZE; m++) {
        for (int n = 0; n < IMG_SIZE; n++) {
            if ((m + n) % 2) {
                data[m * IMG_SIZE + n].real *= -1;
            }
        }
    }
}

int main() {
    FILE *finput = fopen("lena.img", "rb");
    if (finput == NULL) {
        fprintf(stderr, "입력 파일을 열 수 없습니다.\n");
        return 1;
    }
    Complex *signal = (Complex *)malloc(IMG_SIZE * IMG_SIZE * sizeof(Complex));

    // 이미지 데이터 읽기
    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            unsigned char pixel;
            fread(&pixel, sizeof(unsigned char), 1, finput);
            signal[i * IMG_SIZE + j].real = (double)pixel;
            signal[i * IMG_SIZE + j].imag = 0.0;
        }
    }
    fclose(finput);

    centerShift(signal);

    // FFT 수행
    FFT(signal, IMG_SIZE * IMG_SIZE, 1);

    // 주파수 시프트 적용
    shiftFFT(signal, IMG_SIZE, IMG_SIZE);

    // FFT 결과 저장
    FILE *foutput1 = fopen("DFT-magnitude.img", "wb");

    for (int i = 0; i < IMG_SIZE; i++) {
        for (int j = 0; j < IMG_SIZE; j++) {
            int index = i * IMG_SIZE + j;
            double magnitude = sqrt(signal[index].real * signal[index].real + 
                                    signal[index].imag * signal[index].imag);
            magnitude = log(magnitude + 1); // 로그 스케일 변환

            unsigned char pixel = (unsigned char)(magnitude * 255 / log(IMG_SIZE * IMG_SIZE + 1));
            fwrite(&pixel, sizeof(unsigned char), 1, foutput1);
        }
    }

    fclose(foutput1);

    centerShift(signal);

    // 역 FFT 수행
    IFFT(signal, IMG_SIZE * IMG_SIZE);

    // 결과를 0-255 범위로 클리핑
    for (int i = 0; i < IMG_SIZE * IMG_SIZE; i++) {
        signal[i].real = fmin(255.0, fmax(0.0, signal[i].real));
    }

    // 결과 저장
    FILE *foutput_inverse = fopen("Inverse DFT Out.img", "wb");
    if (foutput_inverse == NULL) {
        fprintf(stderr, "출력 파일을 열 수 없습니다.\n");
        free(signal);
        return 1;
    }

    for (int i = 0; i < IMG_SIZE * IMG_SIZE; i++) {
        unsigned char pixel = (unsigned char)(signal[i].real);
        fwrite(&pixel, sizeof(unsigned char), 1, foutput_inverse);
    }

    fclose(foutput_inverse);
    free(signal);
    return 0;
}

// 복소수 곱셈
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// 복소수 뺄셈
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// 복소수 덧셈
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// 복소수 지수 함수
Complex cexp(double phi) {
    Complex result;
    result.real = cos(phi);
    result.imag = sin(phi);
    return result;
}

// FFT 알고리즘 정의
void FFT(Complex signal[], int n, int step) {
    if (step < n) {
        FFT(signal, n, step * 2);
        FFT(signal + step, n, step * 2);

        for (int i = 0; i < n; i += 2 * step) {
            Complex t = multiply(cexp(-2.0 * PI * i / n), signal[i + step]);
            Complex u = signal[i];
            signal[i] = add(u, t);
            signal[i + step] = subtract(u, t);
        }
    }
}

// 역 FFT 알고리즘 정의
void IFFT(Complex signal[], int n) {
    // 복소수 지수 함수에 양의 지수를 사용
    for (int i = 0; i < n; i++) {
        signal[i] = cexp(2.0 * PI * i / n);
    }   
    FFT(signal, n, 1);
    // 결과 스케일링
    for (int i = 0; i < n; i++) {
        signal[i].real *= 1.0 / n;
        signal[i].imag *= 1.0 / n;
    }
}

// 주파수 시프트 함수
void shiftFFT(Complex *data, int width, int height) {
    int halfWidth = width / 2;
    int halfHeight = height / 2;
    for (int i = 0; i < halfHeight; i++) {
        for (int j = 0; j < halfWidth; j++) {
            int idx1 = (i * width) + j;
            int idx2 = ((i + halfHeight) * width) + (j + halfWidth);

            Complex temp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = temp;

            idx1 = ((i + halfHeight) * width) + j;
            idx2 = (i * width) + (j + halfWidth);

            temp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = temp;
        }
    }
}
