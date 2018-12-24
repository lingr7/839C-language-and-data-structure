/*
	Name: 归并排序不适用缓冲区 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 10:54
	Description: 有序部分插入，使用插入排序或选择排序都可以，这里使用插入排序 
*/
void Merge(int *A,int n,int *B,int m){
	int i, j, k;
	for(k = 0; k < m; k++){/*将B数组接在A数组后面存入A数组*/
		A[k+n] = B[k];
	}
	for(i = n; i < n+m; i++){/*在数组A 内部进行插入排序*/
		t = A[i];
		for(j = i; j >= 0 && t < A[j]; j--)
			A[j+1] = A[j];
		A[j+1] = t;
	} 
}
	
