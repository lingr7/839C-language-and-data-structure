/*
	Name: 
	Copyright: 
	Author: malic答案 
	Date: 02/12/18 10:44
	Description: 本题的程序代码是所有元素均不相同的组合情况。
	如果要求从N个数中选M个数输出组合，
	M与N均是已知，那么写M重循环进行遍历就可以。
	但现在循环重数M不能预先知道，这种循环就不能实现。
	这时可以使用用递归，
	每次递归调用进行一重循环，直到循环层数达到要求，
	再输出结果。
	这个程序可以调试。 
*/
#include <stdio.h>
#define MAXN 20
int index[MAXN];
char a[MAXN];

void solve(int n,int m,int level)
{
   int i;
   if(m==level){/*此时index数组已经构建完成*/
	for(i=0;i<m;i++) printf("%c ",a[index[i]]);
	printf("\n"); 
	}
   else{
	for(i=index[level-1]+1;i<n;i++){
	/*这里可以放心的使用i=index[level-1]+1;这一循环起点，因为在56出现过了时，
	再组合一次65绝对是重复了，所以index数组必然是一个首元素最小的数组，
	index[level]只可能比index[level-1]要大*/
	   index[level]=i;
	   solve(n,m,level+1);
	}
   }
}

int main()
{
   int i,n,m;
	
   scanf("%d%d",&n,&m);
   scanf("%s",a);/*a是一个字符数组，也可以当成字符串处理*/
   for(i=0;i<n;i++){/*绝妙*/
	index[0]=i;
	solve(n,m,1);
   }
   return 0;
}
