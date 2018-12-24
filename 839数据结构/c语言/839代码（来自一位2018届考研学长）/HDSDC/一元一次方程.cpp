#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isRight=0;
int xSum=0,Sum=0;
char c;
char s0[80];
int atoi(char s[]){
	int i,n,sign;
	for(i=0;isspace(s[i])||isalpha(s[i]);i++);
	sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]=='-') ++i;
	for(n=0;isdigit(s[i]);i++)
	n=10*n+(s[i]-'0');
	return sign*n;
}
void eval(char *s,int f){
	int n=atoi(s);
	if(f){
        if(n==0) n=1;
		if(isRight>0)
		xSum-=n;
		else 
		xSum+=n;
	}
	else{
		if(isRight>0)
			Sum+=n;
		else 
			Sum-=n;	
	}
	memset(s0,0,80);
}
int main(){
	char s[80];
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(isdigit(s[i])||s[i]=='+'||s[i]=='-'){
			if(s[i]=='+'||s[i]=='-'){
				eval(s0,0);
			}
			strncat(s0,&s[i], 1);
		}
		else if(s[i]=='='){
			eval(s0,0);
			isRight=1; 
		}
		else if(isalpha(s[i])){
			c=s[i];
			eval(s0,1);
		}
	}
	eval(s0,0); 
	printf("%d  %d",Sum,xSum);
	printf("\n%.3f",(float)Sum/xSum);
	return 0;	
}
