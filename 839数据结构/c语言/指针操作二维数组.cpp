#include <stdio.h>
int main(){
	int a[2][3] = {{1,2,3} , {4,5,6}};
	int *p = NULL;
	p = a;
	//p = iArray;
	//printf("a[0][0]=%d\n", *iArray);
	printf("a[0][0]=%d\n", a[0][0]);
	printf("a[1][2]=%d\n", *(p+ 1*3+ 2));
	printf("a[0][0]=%d\n", *p);
	printf("a[1][2]=%d\n", *(p+ 1*3+ 2));

	return 0;
}
