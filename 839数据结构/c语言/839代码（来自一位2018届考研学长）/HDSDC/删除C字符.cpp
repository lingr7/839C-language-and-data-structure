#include<stdio.h>
#include<string.h>
char squeeze(char *s,char x){
	int i,k;
	for(i=0,k=0;i<strlen(s);i++){
		if(s[i]!=x)
		s[k++]=s[i];
	}
	s[k]='\0';
} 
int main(){
	char s[100];
	int i;
	char c;
	printf("Input a stirng:\n");
	gets(s);
	printf("Input x:\n");
	c=getchar();
	squeeze(s,c); 
	puts(s);
	return 0;
}
