/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/12/18 15:00
	Description: 只能取出最右边一位，获得该数补码形式 
	32位版本 
*/
#include <stdio.h>
void print_b(int n);
unsigned int invert(int x , int p , int n)/*特定位取反*/
{
    unsigned int mask= (~(~0<<n)<<(p-n));/*正确结果*/
    /*~(~(~0<<n)<<(p+1-n))*/
	return x^mask;
}
unsigned int invert2(int x , int p , int n)/*现答案*/
{
    unsigned int mask= ~(~(~0<<n)<<(p+1-n));
	return x^mask;
}
void print_b(int n){/*输出有符号整数的二进制位形式*/
	int a[32];
	int i = 0;
	while(i<32){
		a[i] = n & 1;
		n >>= 1;
		i++; 
	}
	for(i = 31; i >= 0; i--){
		printf("%d", a[i]);
	}
	printf("\n");
}
int main(){
	print_b(1);
	print_b(invert(1, 5 ,2));
	//print_b(invert2(1, 5 ,2));
	/* p==5, n==2从右边数第p位，再向右数n位*/
	/*则第5位与第4位取反*/
	print_b(0^1);/*结果1*/
	print_b(1^1); /*结果0*/
	/*与1异或即可取反*/
	return 0;
}
