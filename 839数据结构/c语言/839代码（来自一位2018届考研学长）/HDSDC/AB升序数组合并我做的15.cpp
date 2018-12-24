#include<stdio.h>
void Merge(int *A,int n,int *B,int m){
	int i,j,t;
	for(i=0;i<m;i++){
		t=B[i];
		for(j=n+i-1;j>=0&&t<A[j];j--)
			 A[j+1]=A[j];
		A[j+1]=t;
	}
}
int main(){
	int a[20]={-1,6,28,38};
	int b[20]={2,7,11};
	Merge(a,4,b,3);
	for(int i=0;i<7;i++)
		printf("%5d",a[i]);
	return 0;
} 
