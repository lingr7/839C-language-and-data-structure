#include<stdio.h>
void Insert(int a[],int t,int &n){
	a[n++]=t;
	int i,j;
	int s;
	for(i=(n-2)/2;i>=0;i--){
		s=a[i];
		while((j=2*i+1)<n){
			if(j<n-1&&a[j]<a[j+1]) j++;
			if(s<a[j]){
				a[(j-1)/2]=a[j];
				i=j;
			}
			else break;
		}
		a[(j-1)/2]=s;
	}
}
int main(){
	int a[10]={15,11,7,8,6,4,1};
	int n=7;
	int t;
	printf("Please input a num:\n");
	scanf("%d",&t);
	Insert(a,t,n);
	for(int i=0;i<n;i++)
		printf("%3d",a[i]);
	return 0;
} 
