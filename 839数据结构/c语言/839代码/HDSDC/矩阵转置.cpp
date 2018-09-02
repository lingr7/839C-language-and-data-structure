#include<stdio.h>
void matrixInvert(int **a,int n){
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			int t=*(*a+i*n+j);
			*(*a+i*n+j)=*(*a+j*n+i);
			*(*a+j*n+i)=t;
		}
}

int main(){
	int a[4][4]={1,2,3,4,
			  	 1,2,3,4,
				 1,2,3,4,
				 1,2,3,4};
	int i,j;
	int *q=*a; 
	int **p=&q;  
	matrixInvert(p,4);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%3d",a[i][j]);
			printf("\n");
	}
	return 0;
}

