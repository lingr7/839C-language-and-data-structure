#include<stdio.h>
#include<string.h>
int   Merge(int *A,int n,int *B,int m){
	int i,j;int k,h;
	for(i=0,j=0;B[i];n++,i++){
		while(B[i]>A[j]) j++;
		for(k=n-1;k>=j;k--)
			A[k+1]=A[k];
		A[j]=B[i];	
		j=j+1;
		for(h=0;h<=n;h++)
		printf("%3d ",A[h]);
		printf("\n"); 
	} 
	return n;
}
int main(){
	int a[100]={2,4,6,8,10};
	int b[10]={1,3,113};
 	Merge(a,5,b,2);
	return 0;
	
}
