#include<stdio.h>
#include<math.h>
int Check(int a[],int n){
	int i,j;int ans=0;
	for(i=0;i<n-1;i++){
		if(abs(a[i])>=abs(a[i+1])||a[i]*a[i+1]>=0)
		return 0;
	}
	return 1;
}
int main(){
	int a[10]={-1,2,-3,4,-5,6,-7,8,-9,10};
	int n=Check(a,10);
	if(n==1)
	printf("Right!\n");
	else printf("Wrong!\n");
	return 0;
}
