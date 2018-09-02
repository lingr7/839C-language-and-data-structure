#include<stdio.h>
int  f10_2(int n,int a[]){
	int i,j;
	for(i=0;n>0;i++){
		a[i]=n%2;
		n/=2;
	}
	a[i]='\0';
	return i;	
}
int main(){
	int a[100];
	int i;int n;
	printf("Please input a num:\n");
	scanf("%d",&n);
	printf("转化为二进制:\n");
	for(i=f10_2(n,a)-1;i>=0;i--)
	printf("%d",a[i]);
	return 0;
}
