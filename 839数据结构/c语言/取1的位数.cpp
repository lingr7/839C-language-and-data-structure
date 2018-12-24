/*
	Name: 
	Copyright: 
	Author: 
	Date: 18/12/18 14:59
	Description: 
	https://blog.csdn.net/xhfight/article/details/51534666
*/
#include <stdio.h>
#include <stdlib.h>
 
 
 
int NumberOfOne(int n)
{
 int count = 0;
 /*方法1：最初思路 未解决负数问题
 while(n)
 {
  if((n&1) == 1)
  {
   count++;
  }
  n>>=1;
 }*/
/*方法2：改进1  32位整数要循环32次
 unsigned int flag = 1;
 while(flag)
 {
  if(flag & n)
   count++;
  flag <<= 1;
 }*/
 
 
 //方法3：终极方法 优化了方法2，有多少1就循环多少次
	while(n)
	{
		n &= (n-1);
		count++;
	}
 
 	return count;
}
int main()
{
 	int num = -10;
 
//-10在内存中的存储，求-10的补码
 
//10000000 00000000 00000000 00001010  ->10
//11111111 11111111 11111111 11110101  ->取反
 //11111111 11111111 11111111 11110110  -〉+1
	int ret = NumberOfOne(num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
 

