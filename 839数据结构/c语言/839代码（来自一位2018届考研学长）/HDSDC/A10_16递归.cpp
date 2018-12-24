#include<stdio.h>
void f10_16(int a){
	if(a>0){
		f10_16(a/16);printf("%x",a%16);
	}
	if(a==0) return; 
}
int main(){
	int a;
	printf("Input a number:\n");
	scanf("%d",&a);
	f10_16(a);
	return 0;
} 
