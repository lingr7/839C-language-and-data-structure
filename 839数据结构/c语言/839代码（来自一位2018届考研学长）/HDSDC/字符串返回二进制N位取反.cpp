#include<stdio.h>
void invert(int d,int N,int S,char *s){
	int i;
	for(i=31;i>=0;i--)
	 	s[31-i]=((d>>i)&1)+48;
	s[32]='\0';
	puts(s);
	putchar('\n');
	for(i=31-N;i<=31-S;i++)
	s[i]=49-s[i]+48; 
	puts(s);
}
int main(){
	char s[100];
	int d;
	invert(-3,27,25,s);
	return 0;
} 
