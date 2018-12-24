/*
	Name: 
	Copyright: 
	Author: lingr7
	Date: 20/10/18 23:06
	Description: AB数组合并 
*/

#include<stdio.h>
#include<string.h>
int Merge(int *A,int n,int *B,int m){
	int i,j;
	int k,h;
	for(i=0,j=0;B[i];n++,i++){
		while(B[i]>A[j] && j <= n-1) j++;
	//	printf("此时j==%d\n",j);
		for(k=n-1;k>=j;k--){
	//		printf("此时的A为%d\n", A[k]);
			A[k+1]=A[k];
		}
			
		A[j]=B[i];
		j++;	
	} 
	for(h=0;h<=n-1;h++){
		printf("%4d ",A[h]);
		printf("\n"); 
	}
	
	return n;
}
int main(){
	int a[100]={2,4,6,8,10};
	int b[10]={1,3,113};
 	Merge(a,5,b,3);
	return 0;	
}
