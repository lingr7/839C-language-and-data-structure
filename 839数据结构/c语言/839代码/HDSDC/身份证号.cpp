#include<stdio.h>
#include<ctype.h> 
int main(){
	int f=1,count=0;
	char s[20];
	int w[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char map[20]={'1','0','X','9','8','7','6','5','4','3','2'};
	gets(s);
	for(int i=0;i<17;i++){
		if(!isdigit(s[i])){ //若位数小于18同样可以检测到 
			printf("illegal\n");
			return 0;
		}
		count+=(s[i]-'0')*w[i];
	}
	if(s[17]!=map[count%11]) f=0;
	if(f==0) printf("illegal\n");
	else printf("llegal\n");
	return 0;
} 
