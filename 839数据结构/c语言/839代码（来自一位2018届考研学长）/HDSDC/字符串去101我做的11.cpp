#include<stdio.h>
#include<string.h>
int is(char *s){
	for(int i=0;i<strlen(s)-2;i++)
		if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1')
			return 0;
	return 1;
}
int count_101(int n){
	int i,j,count=0;
	char s[21];
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++)
			s[n-1-j]=((i>>j)&1)+'0';
		s[n]='\0';
		if(is(s)){count++;puts(s); }
	}
	return count;
}
int main(){
	int n;
	scanf("%d",&n);
	n=count_101(n);
	printf("%d",n);
	return 0;
} 
