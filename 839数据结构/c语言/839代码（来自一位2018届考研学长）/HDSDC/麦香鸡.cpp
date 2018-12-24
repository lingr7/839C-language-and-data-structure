#include<stdio.h>
int MCNuggets(int n){
	int i,j,k;
	for(i=0;i<=n/20;i++)
		for(j=0;j<=n/9;j++)
			for(k=0;k<=n/6;k++)
					if(i*20+j*9+k*6==n) return 1;
	return 0; 
} 
int main(){
	int n;
	scanf("%d",&n);
	if(MCNuggets(n))  printf("OK\n");
	else printf("No\n");
	return 0;
}

