#include<stdio.h>
void Inheap(int a[],int t,int &n){
	 int i,j=n;
	 a[n++]=t;
	 while((i=(j-1)/2)>=0){
	 	if(t>a[i]){
	 		a[j]=a[i];
	 		j=i;
		 }
		 else break;
		if(j==0) break; 
	 }
	 a[j]=t;
}
int main(){
	int a[10]={10,7,6,5,4,3,1,2,1};
	int t;
	int n=9;
	printf("Input the num to insert:\n");
	scanf("%d",&t);
	Inheap(a,t,n);
	for(int i=0;i<n;i++)
		printf("%5d",a[i]);
	return 0;
}
