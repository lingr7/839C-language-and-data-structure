#include<stdio.h>
void setbit(int x,int p,int n,int y){
	int a[32],b[32];
	int i,j;
	for(i=31;i>=0;i--)
		a[31-i]=(x>>i)&1;
	for(i=n-1;i>=0;i--)
		b[n-i-1]=(y>>i)&1;
 	for(i=31-p,j=0;i<31-p+n;i++,j++)
 		a[i]=b[j];
 	for(i=0;i<32;i++)
 		printf("%d",a[i]);
}
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	setbit(x,29,5,y);
	return 0;
}
