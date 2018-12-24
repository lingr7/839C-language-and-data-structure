#include<stdio.h>
int power(int n,int m){
	int p=1;
	for(int i=0;i<m;i++)
	p*=n;
	return p;
}
int rightrot(int x,int n){
	int a[65];
	int i,j,count=0;
	for(i=0;i<32;i++)
	a[31-i]=(x>>i)&1;
	for(int i=0;i<32;i++) 
	printf("%d",a[i]);printf("\n");
	for(i=31;i>=0;i--)
	a[i+n]=a[i];
	for(j=n-1,i=31+n;j>=0;j--,i--)
	a[j]=a[i];
	for(int i=0;i<32;i++) 
	printf("%d",a[i]);
	printf("\n");
	if(a[0]==1) a[0]=-1;
	for(i=0;i<32;i++)
	count+=a[i]*power(2,31-i);
	return count;
	
}
int main(){
	int x,n;
	printf("Please input a num:\n");
	scanf("%d",&x);
	printf("Input n:\n");
	scanf("%d",&n);
	n%=32;
	printf("改变后的值为:\n%d",rightrot(x,n));
	return 0;
}
