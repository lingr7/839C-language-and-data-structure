#include <stdio.h>
#include <stdlib.h>
#include <string.h>
float print(int arr[],int n){
    int i=0;
    float sum = 0;
    for(i=0;i<n;i++){
       printf("%d ",arr[i]);
        sum += arr[i];
    }
    printf("\n");
    return sum;
}
// 例如表达式 100a+10=4a-2+123-22a char express[] = "100a+10=4a-2+123-22a";
// 思路：将每个参数全部提取出来100a 10 -4a 2 -123 22a
// 然后将纯数字放入一个数组中
// 变量放在另外一个数组中
double equation(char express[]){/*对方程进行处理*/
    int rightOrleft = 1;/*处理等式左右变号*/
    int next = 1;
    int i=0,m=0,n=0;
    char c = express[i];
    int var[10]; // 提取系数
    int para[10]; // 存放实数
    int top = 0;
    char temp[10];
    if(express[0]=='-'){/*只有部分位置可能会出现代表负号的-，这里是一个*/
        next = -1;
        c = express[++i];
    }
    
    while (c!='\0') {
        if( (c<='9' && c>='0') || (c<='z' && c>='a')){
            //将用于计算的变量或者纯数字缓存起来
            temp[top++] = c;
            temp[top] = '\0';//用于后面的字符串转数字
        } else {
            // 处理加减符号
            top--; //除去末尾的'\0'
            if(temp[top]<='z' && temp[top]>='a'){
                //如果缓存的是变量 1a 3a 100a -1a 末尾必定是字母
                var[m++] = rightOrleft*next*(temp[0]>='a'?1:atoi(temp));/*遇到系数项不在，则系数为1*/
            } else {
                //如果缓存的是纯数字
                para[n++] = rightOrleft*next*(atoi(temp));
            }
            // 对下一个对象正负的判断
            if(c=='-'){
                next = -1;
            } else if(c == '+'){
                next = 1;
            }
            // 缓存清零
            top = 0;/*清空此处记录过的数或者字母*/
        }
        if(c=='='){
            rightOrleft = -1;
        }
        c = express[++i];/*更新c*/
    }
    top--;// 除去最后一个'\0'
    // 处理最后一个参数或者变量
    if(temp[top]<='z' && temp[top]>='a')
        var[m++] = rightOrleft*next*(atoi(temp));
    else
        para[n++] = rightOrleft*next*(atoi(temp));
    return -print(para, n)/print(var, m);
}

int main()
{
    char express[] = "-5a+10=4a-2+123-22a+22";
	/*满足条件，一个绝对典型的一元一次方程，同时开辟的空间大小也由方程决定*/
    printf("%s\na = %.5f\n",express,equation(express));
}
