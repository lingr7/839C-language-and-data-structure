#include<stdio.h>
#include<string.h>
int Reduce(char s[]){
	int count=0;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i-1]==s[i]){
		for(int j=i;j<len;j++){
			s[j]=s[j+1];
		}
		len--;
		s[len]='\0';
		i--;count++;
		}
		
	}
	return count;
}
int main(){
	int i=0;
	char str[50]={"Press***12225"};
	int k;
	printf("Original string:\n");
	puts(str);
	k=Reduce(str);
	printf("\nChanged %d string:\n",k);
	puts(str);
	return 0;
} 
