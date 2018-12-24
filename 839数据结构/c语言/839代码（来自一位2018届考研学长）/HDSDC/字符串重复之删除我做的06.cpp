#include<stdio.h>
#include<string.h>
int  Reduce(char s[]){
	int i=0,j=1;int k=0;
	for(j=1;j<strlen(s);j++){
		if(s[j]!=s[i]) i++;
		else{
			while(s[j]==s[i]){
			 s[j]='m';
			 k++; 
			 j++;
			} 
			i=j;
		}
	}
	for(i=0,j=0;j<strlen(s);j++){	 
  		 if(s[j]!='m'){
  		  s[i++]=s[j];
		}
	}
	s[i]='\0';
	return k;
}
int main(){
	int i=0;
	char str[50]={"Psadfreasdss***122fs25"};
	int k;
	printf("Original string:\n");
	puts(str);
	k=Reduce(str);
	printf("\nChanged %d string:\n",k);
	puts(str);
	return 0;
}
