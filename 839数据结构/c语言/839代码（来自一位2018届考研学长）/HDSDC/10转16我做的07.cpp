#include<stdio.h>
void  f10_16(int n){
	char a[100];int k;int i;
	char jz[16]={'0','1','2','3','4','5',
	'6','7','8','9','A','B','C','D','E','F'};
	for(i=0;n>0;i++){
		a[i]=jz[n%16];
		n/=16;
	}
	printf("转化为16进制:\n0x");
	for(k=i-1;k>=0;k--)
	printf("%c",a[k]);	
} 
int main(){
	int a;int i;
	printf("Please input a num:\n");
	scanf("%d",&a);	
	f10_16( a);
	return 0;
} 
