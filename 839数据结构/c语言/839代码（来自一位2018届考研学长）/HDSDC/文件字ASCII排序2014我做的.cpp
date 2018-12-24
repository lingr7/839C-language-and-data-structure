#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define n 10 
int hash(char *s){
	int i,count=0;
	for(i=0;i<strlen(s);i++)
		if(isalpha(s[i])||isdigit(s[i]))count+=(s[i]-'0');
	return count%1007;	
}
int cmp(const void *a,const void *b){
	char s1[1000];
	char s2[1000];
	strcpy(s1,(char*)a);
	strcpy(s2,(char*)b);
	if(hash(s1)!=hash(s2)) return hash(s1)-hash(s2);
	else if(strlen(s1)!=strlen(s2)) return strlen(s2)-strlen(s1);
	else return strcmp(s2,s1);
}
int main(){
	int i;
	char s[100][1000];
	FILE *fp=fopen("D:\\ll.dat","rb");
	if(fp==NULL){
		printf("Cannot open this file\n");
		exit(1);
	} 
	for(i=0;i<n;i++)
		fscanf(fp,"%s",s[i]);
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0;i<n;i++)
		printf("%s\n",s[i]);
	return 0;
} 
