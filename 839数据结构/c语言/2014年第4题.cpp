/*
	Name: 
	Copyright: 
	Author:本题目属于基本题，7-6，变成6了 
	Date: 16/12/18 20:17
	Description: 
*/
/*第四题，按要求写split函数

设计split传入3个参数，*string是待分割的字符串，key是分隔符，a[][]是目标数组
index记录总共分割的次数，最后分割次数作为split的返回值*/

#include <stdio.h>
int split(char* string,char key,char a[100][100])
{
    int i,index=0,k=0;

    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]!=key)
        {
            a[index][k]=string[i];
            ++k;
        }
        else
        {
            a[index][k]=0;
            index++;
            k=0;
        }
    }
    return index;
}
