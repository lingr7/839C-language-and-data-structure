#include<stdio.h>
 
int findmax(int **a,int i,int j,int h,int w){
	int max=0;
    *(*a+i*w+j)=0;
    max++;
	if(i-1>=0)//ио 
	switch(*(*a+(i-1)*w+j)){
		case 1:max+=findmax(a,i-1,j,h,w);break;
		default:break;
	} 
	if(i+1<h)//об 
	switch(*(*a+(i+1)*w+j)){
		case 1:max+=findmax(a,i+1,j,h,w);break;
		default:break;
	} 
	if(j-1>=0)//вС 
	switch(*(*a+i*w+j-1)){
		case 1:max+=findmax(a,i,j-1,h,w);break;
		default:break;
	} 
	if(j+1<w)//ср 
	switch(*(*a+i*w+j+1)){
		case 1:max+=findmax(a,i,j+1,h,w);break;
		default:break;
	} 
	return max;
}
int maxBlock(int **a,int h,int w){
	int i,j;
	int maxm=0,result;
	for(i=0;i<h;i++)
		for(j=0;j<w;j++)
			if(*(*a+i*w+j)==1){
				result=findmax(a,i,j,h,w);
				if(result>maxm) maxm=result;
			}
				
	return maxm;
}
int main(){
	int a[5][10]={0,0,1,0,0,0,0,0,1,1,
				   0,1,1,0,0,1,1,1,1,1,
				   0,1,0,0,0,1,0,0,0,0,
				   0,0,1,1,1,1,0,1,1,1,
				   0,0,1,1,1,1,0,1,1,1};
 
	int *p=*a;
	int **q=&p;
    printf("%d",maxBlock(q,5,10));
	return 0;
}
