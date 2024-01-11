#include <stdio.h>
#include <string.h>

int main() {
   char ar[21] = {}; // 배열 선언
   int N;
   scanf("%s", ar); // 입력
   scanf("%d", &N);
   if (N < 1 || N > 10) return -1; 
   int idx = strlen(ar); 
   for (int i = 0; i < idx; i++) { // 문자열의 크기만큼 반복
      if (ar[i] >= 'A' && ar[i] <= 'Z') { // 대문자인 경우
         ar[i] = ar[i] + N; // N만큼 앞으로 이동
         printf("%c", ar[i]);
      }
      else if (ar[i] >= 'a' && ar[i] <= 'z') { // 소문자인 경우
         ar[i] = ar[i] - N; // N만큼 뒤로 이동
         printf("%c", ar[i]);
      }
      else if (ar[i] >= '0' && ar[i] <= '9') { // 숫자인 경우
         int k = 0;
         k = ar[i] - '0'; // k에 아스키코드가 아닌 실제 정수 저장

         if (ar[i + 1] >= '0' && ar[i + 1] <= '9') { // 10 이상인 경우
            k *= 10;
            k += ar[i + 1] - '0'; // 아스키코드가 아닌 실제 정수 저장
            i++; // 배열 한칸 이동
         }
         char u = 'A' + k - 1; // 새로운 변수에 알파벳 저장
         for (int j = 0; j < N; j++)
            printf("%c", u);
      }
      else { // 특수문자인 경우
         printf(" ");
      }
   }
   return 0;
}