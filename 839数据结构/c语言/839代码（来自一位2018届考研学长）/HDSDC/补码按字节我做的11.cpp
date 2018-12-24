#include<stdio.h>
unsigned char *i2ba(int n,unsigned char *s){
	unsigned v,b=0;
	for(int i=0;i<32;i+=8){
		 v=n&((~b>>24)<<i);
		 s[i/8]=v>>i;
	}
	s[4]='\0';
	return s;
}
int main(){
	int n;
	unsigned char s[5];
	i2ba(n,s);
	scanf("%d",&n);
	i2ba(n,s); 
	for(int i=0;i<4;i++)
		printf("%-5d",s[i]); 
	return 0;
}
