#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
	char str[10];
	int i,sum=0;
	gets(str);
	if(str[0]=='0'&&(str[1]=='x'||str[1]=='X')){
		for(i=2;i<strlen(str);i++)
			if(isdigit(str[i])){
				sum=sum*16+str[i]-'0';
			}
			else if(str[i]>='a'&&str[i]<='f'){
				sum=sum*16+10+str[i]-'a';
			}
			else if(str[i]>='A'&&str[i]<='F'){
				sum=sum*16+10+str[i]-'A';
			}
			else return 0;
	} 
	printf("%d",sum);
}
