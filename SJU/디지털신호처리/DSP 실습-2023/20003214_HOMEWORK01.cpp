#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void addNoise(unsigned char **image, int width, int height, int FilterSize);
void removeNoise(unsigned char **image, int width, int height);
void lowPassFilter(unsigned char **image, unsigned char **tempImage, int width, int height);
void highPassFilter(unsigned char **image, unsigned char **tempImage, int width, int height);
void saveImage(const char *fileName, unsigned char **image, int width, int height);

int main() {
    FILE *fp;
    unsigned char **input, **tempImage;
    int i, j;
    double val;

    // 메모리 할당
    input = (unsigned char **)malloc(sizeof(unsigned char *) * 512);
    tempImage = (unsigned char **)malloc(sizeof(unsigned char *) * 512);
    for (i = 0; i < 512; i++) {
        input[i] = (unsigned char *)malloc(sizeof(unsigned char) * 512);
        tempImage[i] = (unsigned char *)malloc(sizeof(unsigned char) * 512);
    }

    // 파일 읽기
    fp = fopen("lena.img", "rb");
    for (i = 0; i < 512; i++) {
        fread(input[i], sizeof(unsigned char), 512, fp);
    }
    fclose(fp);
    addNoise(input, 512, 512, 11);
    saveImage("noise_added.img", input, 512, 512);

    fp = fopen("lena.img", "rb");
    for (i = 0; i < 512; i++) {
        fread(input[i], sizeof(unsigned char), 512, fp);
    }
    fclose(fp);
    removeNoise(input, 512, 512);
    saveImage("noise_removed.img", input, 512, 512);

    fp = fopen("lena.img", "rb");
    for (i = 0; i < 512; i++) {
        fread(input[i], sizeof(unsigned char), 512, fp);
    }
    fclose(fp);
    lowPassFilter(input, tempImage, 512, 512);
    saveImage("low_pass_filtered.img", input, 512, 512);

    fp = fopen("lena.img", "rb");
    for (i = 0; i < 512; i++) {
        fread(input[i], sizeof(unsigned char), 512, fp);
    }
    fclose(fp);
    highPassFilter(input, tempImage, 512, 512);
    saveImage("high_pass_filtered.img", input, 512, 512);

    // 메모리 해제
    for (i = 0; i < 512; i++) {
        free(input[i]);
        free(tempImage[i]);
    }
    free(input);
    free(tempImage);
    return 0;
}

void addNoise(unsigned char **image, int width, int height, int FilterSize) {
    for (int n = 0; n < height; n++) {
        for (int m = 0; m < width; m++) {
            // 세로줄 노이즈를 위해 m을 코사인 함수의 인수로 사용
            double cosineValue = 128.0 * cos(2 * M_PI * m / FilterSize) + 128;
            int newValue = (int)(image[n][m] + cosineValue);

            // 값이 0에서 255 사이가 되도록 조정
            image[n][m] = (unsigned char)(fmax(0, fmin(255, newValue)));
        }
    }
}


void removeNoise(unsigned char **image, int width, int height) {
    int FilterSize = 11; // 예를 들어 필터 크기를 3으로 설정
    int halfSize = FilterSize / 2; // 필터 크기의 절반
    unsigned char **tempImage = (unsigned char **)malloc(sizeof(unsigned char *) * height);
    for (int i = 0; i < height; i++)
        tempImage[i] = (unsigned char *)malloc(sizeof(unsigned char) * width);
    
    // 이미지의 모든 픽셀을 순회
    for (int i = halfSize; i < height - halfSize; i++) {
        for (int j = halfSize; j < width - halfSize; j++) {
            int sum = 0;
            // 현재 픽셀을 중심으로 하는 FilterSize x FilterSize 윈도우의 픽셀 값들을 더함
            for (int di = -halfSize; di <= halfSize; di++) {
                for (int dj = -halfSize; dj <= halfSize; dj++) {
                    sum += image[i + di][j + dj];
                }
            }
            // 계산된 합을 필터 크기의 제곱으로 나누어 평균을 구함
            tempImage[i][j] = sum / (FilterSize * FilterSize);
        }
    } 
    // 임시 이미지로부터 원본 이미지로 결과를 복사
    for (int i = halfSize; i < height - halfSize; i++) {
        for (int j = halfSize; j < width - halfSize; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
    // 임시 이미지 메모리 해제
    for (int i = 0; i < height; i++)
        free(tempImage[i]);
    free(tempImage);
}


void lowPassFilter(unsigned char **image, unsigned char **tempImage, int width, int height) {
    // 평균 필터 적용
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int sum = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    sum += image[i + di][j + dj];
                }
            }
            tempImage[i][j] = sum / 9;
        }
    }

    // 결과를 원본 이미지로 복사
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
}

void highPassFilter(unsigned char **image, unsigned char **tempImage, int width, int height) {
    // 소벨 연산자를 이용한 고역 통과 필터링
    int gx, gy;
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            // 수평 경계를 감지하기 위한 Gx 계산
            gx = image[i - 1][j - 1] + 2 * image[i][j - 1] + image[i + 1][j - 1]
               - image[i - 1][j + 1] - 2 * image[i][j + 1] - image[i + 1][j + 1];
            
            // 수직 경계를 감지하기 위한 Gy 계산
            gy = image[i - 1][j - 1] + 2 * image[i - 1][j] + image[i - 1][j + 1]
               - image[i + 1][j - 1] - 2 * image[i + 1][j] - image[i + 1][j + 1];
            
            // 소벨 연산자의 결과를 계산하여 픽셀값으로 설정
            tempImage[i][j] = (unsigned char)(fmin(255, fmax(0, sqrt(gx * gx + gy * gy))));
        }
    }

    // 임시 이미지에서 처리된 값을 원본 이미지로 복사
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            image[i][j] = tempImage[i][j];
        }
    }
}


void saveImage(const char *fileName, unsigned char **image, int width, int height) {
    FILE *fp = fopen(fileName, "wb");
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(unsigned char), width, fp);
    }
    fclose(fp);
}