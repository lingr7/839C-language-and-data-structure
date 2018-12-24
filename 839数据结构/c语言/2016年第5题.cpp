/*
	Name: 文件读写 
	Copyright: 
	Author: malic答案 
	Date: 15/12/18 21:45
	Description: 题目可知，
	按商品名排序，相同品名的商品都相邻，
	这样不需要造hash表。 
	每读到一行就与上一行的商品名相比，
	如果一样就累加收入，
	不一样则就把上一个商品输出到文件，再开始对下一个商品进行累计。
程序中定义了brand[2][82]用于保存商品名，
也就是有brand[0]和brand[1]两个char数组，
当前商品名的下标为k时，
另一个商品名为1-k，
可以省去反复的对字符串的复制操作的开销。
程序中如果刚读到的商品名和当前操作的商品名一致，
则加到累加，若不一致则输出当前的商品名brand[k]，
并把当前操作的商品名调整为k=1-k。
最后读文件到EOF结束后，
当前操作的文件肯定不会输出，所以在循环外需要单独将最后一次操作的商品信息输出到文件当中。

这种逐行读取的思路很棒，节约资源，像极了oj题目的操作手段，只不过由标准的输入输出改造为文件读写了*/


#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    FILE *fin,*fout;
    char brand[2][82];
    double sum,price;
    int k=0;

    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");

    fscanf(fin,"%s%lf",brand[k],&price);
    sum=price;
    
    while(fscanf(fin,"%s%lf",brand[1-k],&price)!=EOF)
    {
        if(strcmp(brand[0],brand[1])==0)
        {
            sum+=price;
        }
        else
        {
            
            fprintf(fout,"%s %.2f\n",brand[k],sum);
            sum=price;
            k=1-k;
        }
    }
    fprintf(fout,"%s %.2f\n",brand[k],sum);
    fclose(fin);
    fclose(fout);
    return 0;
}
