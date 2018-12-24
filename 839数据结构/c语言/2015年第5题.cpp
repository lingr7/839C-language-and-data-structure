/*
	Name: 
	Copyright: 
	Author: malic答案 
	Date: 17/12/18 08:31
	Description: 第五题的难度，额，不定，有时难，有时又没有那么难 
	关键在于并非只有0-9参与数独，还可以有无数个正整数参与。 
*/
/*五、文件中存放着N2*N2(3<N<6)大小的矩阵,
矩阵元素均为[1,N2]的整数。
请你写程序判断文件中保存的矩阵是否满足数独的要求*/

    
#include <stdio.h>
#define MAXN 6
#define MAXRANGE 36
int main(void)
{
    FILE *fp;
    int RANGE,ORDER;
    int i,j,k1,k2;
    int judgeFlag=1;
    int sudoku[MAXRANGE][MAXRANGE];
    char bucket[MAXN*MAXN];

    fp=fopen("dataIN","r");
    fscanf(fp,"%d",&ORDER);
    RANGE=ORDER*ORDER;
    for(i=0;i<RANGE;i++)
        for(j=0;j<RANGE;j++)
            fscanf(fp,"%d",&sudoku[i][j]);/*二维数组存储*/

    for(i=0;judgeFlag==1 && i<RANGE;i++)/*出现一次就跳出循环*/
    {
        for(j=0;j<=RANGE;j++)
            bucket[j]=0;/*这是因为一行出现的每个数，都要有访问次数的标记*/
        for(j=0;j<RANGE;j++)
            bucket[sudoku[i][j]]+=1;/*逐行*/
        for(j=1;j<=RANGE;j++)
            if(bucket[j]!=1){/*出现不止一次*/
                judgeFlag=0;
                break;
            }
    }

    for(j=0;judgeFlag==1 && j<RANGE;j++)/*逐列思路类似*/
    {
        for(i=0;i<RANGE+1;i++)
            bucket[i]=0;
        for(i=0;i<RANGE;i++)
            bucket[sudoku[i][j]]+=1;/*这里似乎不对啊*/
        for(i=1;i<=RANGE;i++)
            if(bucket[i]!=1){
                judgeFlag=0;
                break;
            }
    }

    for(k1=0;judgeFlag==1 && k1<RANGE;k1+=ORDER)
    {
        for(k2=0;judgeFlag==1 && k2<RANGE;k2+=ORDER)
        {
            for(i=0;i<RANGE+1;i++)/*1-n的平方，这些数的被访问次数*/
                bucket[i]=0;

            for(i=0;i<ORDER;i++)
                for(j=0;j<ORDER;j++)        
                    bucket[sudoku[k1+i][k2+j]]++;

            for(i=1;i<=RANGE;i++)
                if(bucket[i]!=1)
                {
                    judgeFlag=0;
                    break;
                }
        }
    }
    if(judgeFlag)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
