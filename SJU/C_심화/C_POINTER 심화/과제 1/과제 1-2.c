#include <stdio.h>

int *MAX(int ar[]); // 원형 함수 선언
int *MIN(int ar[]);

int main(){
   int N; // 변수 지정
   int max_idx,min_idx;
   int tmp;
   scanf("%d",&N);

   for(int i=0; i<N; i++){ // N번 만큼 반복
      int cnt=0,cnt2=0;
      int ar[100];
      int *p = ar; // 포인터와 배열 선언 및 연결
      int *p_max, *p_min; // max, min 인덱스 주소를 가리킬 포인터
      

      while(1){ // 무한루프 (조건문으로 종료)
         scanf("%d",p);
         if(*p == 0)break; // 포인터의 값이 0이 되면 종료
         cnt++; //포인터의 길이를 찾기 위한 카운트
         p++;
      }
      if(cnt == 0) // 맨 처음 인덱스에 0이 들어간 경우
         return -1;

      if(cnt == 1 || cnt == 2){ // 값이 하나인 경우
         printf("none\n");
         continue;
      }
      
      p = ar; // 포인터 초기화
      p_max = MAX(p); // 최대값 주소를 담을 포인터
      p = ar; // 포인터 초기화
      p_min = MIN(p); // 최소값 주소를 담을 포인터
      p = ar;
   
      for(; p<ar+cnt; p++){ 
         if(*p == *p_max){ // 반환 받은 최대값과 포인터의 값이 같은 위치 저장
            max_idx = cnt2;
            break;
         }
         cnt2++; // 인덱스 위치 확인
      }
      p = ar;
      cnt2 = 0;
      for(; p<ar+cnt; p++){ 
         if(*p == *p_min){ // 반환 받은 최소값과 포인터의 값이 같은 위치 저장
            min_idx = cnt2;
            break;
         }
         cnt2++; // 인덱스 위치 확인
      }
     //printf("%d  %d\n",min_idx, max_idx);
      p = ar; // 포인터 초기화
      if(max_idx < min_idx){ // 더 큰 값이 max값으로 더 작은 값이 min값으로 스왑
         tmp = min_idx;
         min_idx = max_idx;
         max_idx = tmp;
      }
      if(min_idx == max_idx){ // 만약 최대 최소값이 같은 경우
         printf("none\n");
         continue;
      }
      //printf("%d  %d\n",min_idx, max_idx);
	  if(max_idx - min_idx == 1){ // 최대값과 최소값 사이에 값이 없으면 none출력
		  printf("none\n");
		  continue;
	  }
      for(p=ar + min_idx + 1; p<ar + max_idx; p++) // 결과값 출력
        printf("%d ",*p);
      printf("\n");
   }

   return 0;
}

int *MAX(int ar[]){
   int *p = ar; // 포인터 선언 및 배열과 연결
   int cnt=0,max=0,cnt2=0,idx=0; // 변수 선언
   while(1){ // 무한루프 (조건문으로 종료)
      if(*p == 0)break; // 포인터의 값이 0이 되면 종료
      p++;
      cnt++; // 포인터의 길이 확인
   }
   p = ar; // 포인터 초기화
   for(; p<ar+cnt; p++){ // 포인터 한 바퀴 반복
      if(max < *p){ // 맥스값 지정 및 인덱스 저장
         max = *p;
         idx = cnt2;
      }
      cnt2++; // 지정 할 인덱스
   }
   p = ar;
   return p+idx; // 포인터의 주소 반환
}

int *MIN(int ar[]){
   int *p = ar; // 포인터 선언 및 배열과 연결
   int cnt=0,min=1000000000,cnt2=0,idx=0; // 필요한 변수 선언
   while(1){ // 무한루프 (조건문으로 종료)
      if(*p == 0)break; // 포인터의 값이 0이되면 종료
      p++;
      cnt++; // 포인터의 길이 확인
   }
   p = ar; // 포인터 초기화
   for(; p<ar+cnt; p++){ // 포인터 한 바퀴 반복
      if(min > *p){ // 최소값 구하고 해당 인덱스 저장
         min = *p;
         idx = cnt2;
      }
      cnt2++; // 저장 할 인덱스
   }
   p = ar; 
   return p+idx; // 포인터의 주소 반환
}