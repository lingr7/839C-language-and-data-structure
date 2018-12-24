#include<stdio.h>
#define N 3
#define M 3
void matrixInvert(int **a, int n)
{
	int tmp;
	for (int i = 0; i < n; i++){
		for (int j = i; j < n; j++){
			tmp = *((int *)a + i*n +j);
			*((int *)a + i*n +j) = *((int *)a + j*n +i);
			*((int *)a + j*n +i) = tmp;
		}
	}
}
int main(){
    int i, j , a[N][M],b[M][N];
    //´Ó¼üÅÌÊäÈë¾ØÕóa
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("a[%d][%d]= ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    //Êä³ö¾ØÕóa
    printf("Array a:\n");
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%5d",a[i][j]);
            b[j][i]=a[i][j];
        }
        printf("\n");
    }
    //Êä³ö¾ØÕób
    printf("Array b:\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("%5d",b[i][j]);
        }
        printf("\n");
    }
    matrixInvert(&a, 3);

}

