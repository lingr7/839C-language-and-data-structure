#include<stdio.h>
#include<string.h>
char *ui2hex(unsigned n,char *s){
	int i;
	char acs[16]={'1','2','3','4','5','6','7','8','9','A',
	'B','C','D','E','F'};
	for(i=0;n>0;i++){
		s[i]=acs[n%16]-1;
		n/=16; 
	}
	s[i++]='x';s[i++]='0';s[i]='\0';
	return s;
}
int main(){
	unsigned int n;
	printf("Please input a num:\n");
	scanf("%u",&n);
	char s[100];
	ui2hex(n,s);
	for(int i=strlen(s)-1;i>=0;i--)
	printf("%c",s[i]);
	return 0;
} 
