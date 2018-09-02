#include<stdio.h>
void C(int n,int k){
	unsigned long long yh[51][51];
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=i;j++){
			if(j==0||j==i) yh[i][j]=1;
			else yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
		} 
	printf("%I64u",yh[n][k]);	
}
int main(){
	int n=0,k=0;
	scanf("%d%d",&n,&k);
	while(n<1||n>50||k<1||k>n){
	printf("Please input the right value:\n");
	scanf("%d%d",&n,&k);
	}
	C(n,k);
	return 0;
}
