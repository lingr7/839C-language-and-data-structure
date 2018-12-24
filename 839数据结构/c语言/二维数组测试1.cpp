/*
	Name: 
	Copyright: 
	Author: 
	Date: 30/11/18 22:30
	Description: 这里证明二维数组的数组名的值，第一行的值，第一行第一列的地址是同样的东西 
    数组名a+1就移动到下一个行向量，即指向另一个行向量，同时指向该行向量的第一个元素 
*/
#include<stdio.h>

int main() {

    int a[2][3] = {{1,2,3},{4,5,6}};

    printf("\n");
    printf("a[0]的值:%x\n",a[0]);
    printf("a[0][0]的地址:%x\n",&a[0][0]);
    printf("a的值:%x\n",a);

    printf("\n");
    printf("a[1]的值:%x\n",a[1]);
    printf("a[1][0]的地址:%x\n",&a[1][0]);
    printf("a+1的值:%x\n",a+1);

}
