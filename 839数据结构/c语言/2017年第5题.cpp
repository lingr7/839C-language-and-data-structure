/*
	Name: 还是结构体排序，文件读写 
	Copyright: 
	Author: malic答案 
	Date: 15/12/18 21:43
	Description: 
	五、文本文件data.in当中，
	有多行数字，
	每行有4个浮点数x1 y1 x2 y2，
	分别表示矩形的左下角与右上角顶点的两个坐标(x1,y1) (x2,y2).
现在请你写一个程序，
对这些矩形进行排序。
排序的规则为：
先按矩形面积从小到大排序，
如果面积相同，
则按左下角顶点到原点的距离从小到大排序，
如果再相同，按左下角顶点的横坐标x1从小到大排序。
将排序后的数据再写到文件data.out当中，
面积为0的矩形不输出
*/

#include <stdio.h>
#define MAXN 200
struct pNode
{
    double x1,y1;
    double x2,y2;
    double area,distance;
};
typedef struct pNode Point;

int cmp(const void *a,const void *b)
{
    Point m=*(Point*)a,n=*(Point*)b;
    if(m.area!=n.area)
        return m.area-n.area;
    else if(m.distance!=n.distance)
        return m.distance-n.distance;
    else
        return m.x1-n.x1;
}

int main(void)
{
    FILE *fp,*fout;
    int i=0,N;
    Point a[MAXN];

    fp=fopen("data.in","r");
    while(fscanf(fp,"%f",&a[i].x1))
    {
        fscanf(fp,"%f%f%f",&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].area=(a[i].y2-a[i].y1)*(a[i].x2-a[i].x1);
        a[i].distance=a[i].x1*a[i].x1+a[i].y1*a[i].y1;
        i++;
    }
    fclose(fp);

    N=i;
    qsort(a,N,sizeof(a[0]),cmp);

    fout=fopen("data.out","w");
    for(i=0;i<N;i++)
    {
        fprintf(fout,"%f %f %f %f\n",a[i].x1,a[i].y1,a[i].x2,a[i].y2);
    }
    fclose(fout);
    return 0;
}
