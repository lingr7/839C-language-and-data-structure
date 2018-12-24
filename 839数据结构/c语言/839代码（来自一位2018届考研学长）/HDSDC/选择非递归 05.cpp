#include<stdio.h>
void sort(int *p,int n){
	 int i,j,k;
	 if(n>0){
		 for(i=0;i<n-1;i++){
	 		k=i;
	 		for(j=i+1;j<n;j++)
	 		if(p[k]>p[j])
		  		k=j;
			int t=p[k];
			p[k]=p[i];
			p[i]=t;
	 	 }	 
	 sort(p++,--n);
	}
}
int main(){
	int a[10]={-5,8,10,-1,14,25,15,6,11,3};
	sort(a,10);
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
} 
