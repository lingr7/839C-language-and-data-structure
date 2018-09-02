#include<stdio.h>
#include<string.h>
typedef struct{
	int x;
	int y;
}POINT;
POINT  Go(POINT p0,char steps[]){
	int i,j; 
	int n=strlen(steps);
	for(i=0,j=0;i<n/2;i++)
	switch(steps[2*i]){
		case 'E': p0.x+=steps[2*i+1]-48; break;
		case 'W': p0.x-=steps[2*i+1]-48; break;
		case 'N': p0.y+=steps[2*i+1]-48; break;
		case 'S': p0.y-=steps[2*i+1]-48; break;
		default : printf("Input Wrong!\n"); break;
	}
	return  p0;	
}
int main(){
	POINT p0,a;
	p0.x=-4;
	p0.y=1;
	char str[100];
	printf("Please input the tracks:\n");
	gets(str);
	a=Go(p0,str);
	printf("x=%d,y=%d",a.x,a.y);
	return 0;
}
