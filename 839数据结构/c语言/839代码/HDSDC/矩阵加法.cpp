#include<stdio.h>
#define ROW 4
#define COL 4
void matrixAdd(int **a,int **b,int**c,int row,int col){
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			*(*c+col*i+j)=*(*a+col*i+j)+*(*b+col*i+j);		
}
int main(){
	int a[ROW][COL]={1,2,3,7,
				     2,4,6,2,
				     1,5,3,9,
				     -3,2,8,4,
				    };
	int b[ROW][COL]={1,1,8,1,
				     1,7,1,5,
				     -2,3,9,1,
				     1,8,1,4,
				    };
	int c[ROW][COL]={0};
	int *q1=*a;
	int **p1=&q1;
	int *q2=*b;
	int **p2=&q2;
	int *q3=*c;
	int **p3=&q3;
	matrixAdd(p1,p2,p3,ROW,COL);
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++)
			printf("%5d",c[i][j]);
			printf("\n");
	}
	return 0;
}




