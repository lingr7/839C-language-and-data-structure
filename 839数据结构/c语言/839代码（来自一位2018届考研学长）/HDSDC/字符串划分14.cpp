#include<stdio.h>
#include<string.h>
int split(char *s,char c,char ss[][1000]){
	int i,j,k;
	for(i=0,j=0,k=0;i<strlen(s);i++)
		if(s[i]!=c) ss[k][j++]=s[i];
		else{
			ss[k][j]='\0';
			j=0;
			if(i<strlen(s)-1) k++;
			else return k;
			}
   	ss[k][j]='\0';
   	 
   	return k;
}
int main(){
	char s0[1000];
	char c;
	int k;
	char s[100][1000];
	gets(s0);
	scanf("%c",&c);
    k=split(s0,c,s);
	for(int i=0;i<=k;i++)
	puts(s[i]);
	return 0;
} 
