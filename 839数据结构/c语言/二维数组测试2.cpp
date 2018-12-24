/**
**  @author:hushunfeng
**    
*/
#include<stdio.h>

int main() {

    int a[2][3] = {{1,2,3},{4,5,6}};

    int **p = a;
    
    printf("\n");
    printf("a[0][0]的地址:%x\n",&a[0][0]);
    printf("a[0][0]的地址:%x\n", *p);
    
    printf("p+1之前：%d\n",p);
    p++;
    printf("p+1之后：%d\n",p);

}
