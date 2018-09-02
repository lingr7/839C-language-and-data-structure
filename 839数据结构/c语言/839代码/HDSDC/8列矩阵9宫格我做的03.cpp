#include<stdio.h>
int value9(int d[][8],int n,int i,int j,int*v){
	*v=0;
	if(i<1||i>n-2||j<1||j>6)
	return 0;
	i--;j--;
	int i1,j1;
	for(i1=i;i1<i+3;i1++)
		for(j1=j;j1<j+3;j1++){
			*v+=d[i1][j1];		 
		}	
return 1;
}
int main(){
	int s1[3][8]={1,2,3,4,5,6,7,8,
	9,10,11,12,13,14,15,16,
	17,18,19,20,21,22,23,24};
	int p;int p1,q1;int v;
	printf("Please input i&j£º\n");
	scanf("%d%d",&p1,&q1);
	value9(s1,3,p1,q1,&v);
	printf("%d",v);
	return 0;	
}
