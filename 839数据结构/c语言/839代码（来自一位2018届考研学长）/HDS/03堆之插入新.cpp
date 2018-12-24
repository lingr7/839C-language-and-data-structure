#include<stdio.h>
void Insert(int s[],int n,int t){
	s[n]=t;
	int i,j;
	for(j=n,i=(n-1)/2;i>=0;i=(i-1)/2){
		if(s[i]<t){
		s[j]=s[i];
		j=i;
		}
		if(j==0||s[i]>=t) break;
	}
	s[j]=t;
}
int main(){
	int a[10]={18,17,11,9,5,3,6,4};
	int t;
	scanf("%d",&t);
	Insert(a,8,t);
	for(int i=0;i<9;i++)
		printf("%3d",a[i]);
	return 0;
} 
