#include<stdio.h>
#include<string.h>
int main(){
	int n,m;
	int i,pos,count;
	char s[20],a[20];
	gets(s);
	printf("Please input n&m\n");//n3 m2
	scanf("%d%d",&n,&m); 
	for(i=0;i<(1<<n);i++){
		count=0;
		for(pos=0;pos<n;pos++)
			if((i>>pos)&1)
				a[count++]=s[pos];
		if(count==m){
			a[count]='\0';
			printf("%s\n",a);
		}
	}
	return 0;
} 
