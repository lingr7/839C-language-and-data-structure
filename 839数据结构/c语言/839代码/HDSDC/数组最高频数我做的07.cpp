#include<stdio.h>
#include<string.h>
int f(int p[],int *n){
	*n=0;
	int e=1,max=0,index;
	int i,j;
	for(i=0;p[i];i++){
		for(j=0;p[j];j++){
			if(p[j]==p[i]) e++;
		}
		if(e>max){
		max=e; index=i;
		}  
		e=0;
	}
	*n=max;
	return  p[index]; 
} 	
int main(){
	int a[50]={1,6,6,6,6,2,5,11,1,1,1,1,1,1,5,5,6,8,9,20,10,
	20,30,6,6,6,20,20,20,6};
	int  n;int m;
	n=f(a,&m);
	printf("最大的数为:%d\n",n);
	printf("出现的次数:%d\n",m);
	return 0;
}
