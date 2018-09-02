#include<stdio.h>
int search(int **a,int i,int h,int j,int w){
	int max=1;
	*(*a+i*w+j)=0;
	if(i>0&&*(*a+(i-1)*w+j)) max+=search(a,i-1,h,j,w);
	if(i<h-1&&*(*a+(i+1)*w+j)) max+=search(a,i+1,h,j,w);
	if(j>0&&*(*a+i*w+j-1)) max+=search(a,i,h,j-1,w);
	if(j<w-1&&*(*a+i*w+j+1)) max+=search(a,i,h,j+1,w);
	return max;
}
int maxBlock(int **a,int h,int w){
	int max=0,m;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++) 
			if(*(*a+i*w+j)&&(m=search(a,i,h,j,w))>max)
		    max=m;
	return max;
}
int main(){
	int  a[5][10]={0,0,1,0,0,0,0,0,1,1,
				   0,1,1,0,0,1,1,1,1,1,
				   0,1,0,0,0,1,0,0,0,0,
				   0,0,1,1,1,1,0,1,1,1,
				   0,0,1,1,1,1,0,1,1,1};
	int *p=a[0];
	int **q=&p;
	int max=maxBlock(q,5,10);
	printf("The max block:\n%d",max);
	return 0;
} 

