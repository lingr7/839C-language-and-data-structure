#include<stdio.h>
int invert1(int x,int p,int n,char *s){
	int a[32];int i,sum=0;
	for(i=31;i>=0;i--)
		a[31-i]=(x>>i)&1;
	printf("value:\n");
	for(i=31-p;i<31-p+n;i++)
		a[i]=1-a[i];
	for(i=0;i<32;i++)
		s[i]=a[i]+48;
	s[i]='\0';	
}
int invert2(int d,int p,int n,char *s){
	int num=d^(~(~0<<n)<<(p+1-n));
	for(int i=31;i>=0;i--)
		s[31-i]=((num>>i)&1)+48;
	s[32]='\0';
}
int main(){
	int x,p,n;
	char s1[100],s2[100];
	printf("Input x,p,&n:\n");
	scanf("%d%d%d",&x,&p,&n);
	invert1(x,p,n,s1);
    invert2(x,p,n,s2);
    puts(s1);
    puts(s2);
	return 0;
}  
