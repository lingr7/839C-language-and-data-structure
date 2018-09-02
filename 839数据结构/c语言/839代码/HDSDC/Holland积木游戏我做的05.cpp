#include<stdio.h>
typedef enum colour{
	red,yellow,blue
}color;
void swap(color *p[8],int i,int j){
	color *r=p[i];
	p[i]=p[j];
	p[j]=r;	 
}
int inspect(color **p,int i){
	return *p[i];
} 
void holland(color *pc[],int n){
	int k,i,j;	
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++) 
			if(inspect(pc,j)<inspect(pc,k)) k=j;
		swap(pc,i,k);
	}
}
int main(){
	color c[3]={red,yellow,blue};int i;
	color *p[8]={&c[1],&c[0],&c[0],&c[2],&c[1],&c[2],
	&c[0],&c[2]}; 
	holland(p,8);
	for(i=0;i<8;i++)
	printf("%d",*p[i]);
	return 0;	
}
 
