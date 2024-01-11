#include <stdio.h>
int main(void)
{
    int n=0; int r=0; long long s=1; int nt=0; long long js=1;
    int rt=1; long long jj=1; int jt=0; long long j=1;

    scanf("%d %d",&n,&r); 
    if(n < r || r <= 0){ 
        printf("inputs n and r must satisfy '0 < r <= n'.");
        return -1;
    }

    nt = n;
    for(int i=0; i<r; i++){
        s = s * nt;
        nt--;
    }
    printf("%dP%d=%lld\n",n,r,s);

    for(int i=0; i<r; i++){
        js = js * n; 
    }
    printf("%dPI%d=%lld\n",n,r,js);

    for(int i=1; i<=r; i++){
        rt = rt * i;
    }
    j = s/rt;
    printf("%dC%d=%lld\n",n,r,j);

    jt = n + r -1; 
    for(int i=1; i<=r; i++){
        jj = jj * jt;
        jt--;
    }
    jj = jj / rt; 
    printf("%dH%d=%lld",n,r,jj);


  return 0;
}