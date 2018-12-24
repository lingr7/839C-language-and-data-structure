/*
	Name: 动态规划方法生成最优二叉查找树 - lpshou - 博客园  
	Copyright: 
	Author: 
	Date: 11/12/18 22:48
	Description: http://www.cnblogs.com/lpshou/archive/2012/04/26/2470914.html
*/
#include<stdio.h>
#include<stdlib.h>
#define max 9999
void OptimalBST(int,float*,float**,int**);
void OptimalBSTPrint(int,int,int**);
int main()
{
    int i,num;
    FILE *point;
    //所有数据均从2.txt中获取，2.txt中第一个数据表示节点个数；从第二个数据开始表示各个节点的概率
    point=fopen("2.txt","r");
    if(point==NULL)
    {
        printf("cannot open 2.txt.\n");
        exit(-1);
    }
    fscanf(point,"%d",&num);
    printf("%d\n",num);
    float *p=(float*)malloc(sizeof(float)*(num+1));/*这里为啥这么麻烦啊*/
    for(i=1;i<num+1;i++)
        fscanf(point,"%f",&p[i]);
    //创建主表；
    float **c=(float**)malloc(sizeof(float*)*(num+2));
    for(i=0;i<num+2;i++)
        c[i]=(float*)malloc(sizeof(float)*(num+1));
    //创建根表；
    int **r=(int**)malloc(sizeof(int*)*(num+2));
    for(i=0;i<num+2;i++)
        r[i]=(int*)malloc(sizeof(int)*(num+1));
    //动态规划实现最优二叉查找树的期望代价求解。。
    OptimalBST(num,p,c,r);
    printf("该最优二叉查找树的期望代价为：%f \n",c[1][num]);
    //给出最优二叉查找树的中序遍历结果；
    printf("构造成的最优二叉查找树的中序遍历结果为：");
    OptimalBSTPrint(1,4,r);

}
void OptimalBST(int num,float*p,float**c,int**r)
{
    int d,i,j,k,s,kmin;
    float temp,sum;
    for(i=1;i<num+1;i++)//主表和根表元素的初始化
    {
    
        c[i][i-1]=0;
        c[i][i]=p[i];
        r[i][i]=i;
    }
    c[num+1][num]=0;
    for(d=1;d<=num-1;d++)//加入节点序列
    {
        for(i=1;i<=num-d;i++)
        {
            j=i+d;
            temp=max;
            for(k=i;k<=j;k++)//找最优根
            {
                if(c[i][k-1]+c[k+1][j]<temp)
                {
                    temp=c[i][k-1]+c[k+1][j];
                    kmin=k;
                }
            }
            r[i][j]=kmin;//记录最优根
            sum=p[i];
            for(s=i+1;s<=j;s++)
                sum+=p[s];
            c[i][j]=temp+sum;
        }
    }
}
//采用递归方式实现最优根的输出，最优根都是保存在r[i][j]中的。。。
void OptimalBSTPrint(int first,int last,int**r)
{

    int k;
    if(first<=last)
    {
        k=r[first][last];
        printf("%d  ",k);
        OptimalBSTPrint(first,k-1,r);
        OptimalBSTPrint(k+1,last,r);
    }
}
