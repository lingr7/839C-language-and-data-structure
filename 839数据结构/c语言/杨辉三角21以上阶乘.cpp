#include <stdio.h>
#define MAXN 82
long long solve(int N,int M)
{
    int i,j;
    long long a[MAXN];
    for(i=0;i<=N;i++)
    {
        a[0]=1;
        a[i]=1;
        if(i>1)
            for(j=i-1;j>0;j--)
                a[j]=a[j]+a[j-1];
    }
    return a[M];
}
int main(void)
{
    int N,M;
    scanf("%d%d",&N,&M);
    printf("%lld\n",solve(N,M));
    return 0;
}
