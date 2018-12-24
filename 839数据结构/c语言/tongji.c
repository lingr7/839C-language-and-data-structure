#include <stdio.h>
#include <ctype.h>
#define MAXWORD 100
#define MAXLEN 1000
/*从输入中读取下一个单词或字符*/

char *getword(char *word, int lim);
char getch();
void ungetch(char);
char allocbuf[MAXLEN] = "af"; 
int bufp = 2;

int main()
{
    char word[MAXWORD];
    printf("%s\n", getword(word, MAXWORD));
    return 0;
}
//从输入中读取下一个单词或字符，返回第一个字符
char *getword(char *word, int lim)
{
    char c, *p = word;   //, *w = word;  //此处，是我一开始自己敲出代码后出错的地方，因为我没有按照课本上写的那样，将

    *w = word; 全代码都是对 word地址进行操作，对其进行地址++等等，后来发现，整个代码输出的代码结果是空结果。然后找出原因，如果将函数传过来的参数 *word 进行操作，不能保留储存结果，也就是在这个函数中，系统只是将  char *word当作char类型的word变量使用而已，所以，要想储存对word的操作，必须先将 *w = word 进行地址引入，用 *w 保存结果。
    while(isspace(c = getch()))
        ;
    if(c != EOF){
        *word++ = c;
        //w++;
    }
    if(!isalpha(c)){
        *word = '\0';
        return c;
    }
    for(; --lim > 0; word++){

        if(!isalnum(*word = getch())){
            ungetch(*word);
            break;
        }
    }
    *word = '\0';
    return p;
}
//获取字符
char getch()
{
    char c;
    if(bufp == 0)
    {
        printf("需要手动输入\n");
        c = getchar();
        getchar();  //用来获取上一个getchar之后输入的换行符，不然的话，程序会自动将换行符当作下一个输入的字符，然后终止                             程序。 这个是课本上没有的一行代码。
        return c;
    }
    else
        return allocbuf[--bufp];
    //return (bufp > 0)  allocbuf[--bufp]: getchar();  
}
//返回字符
void ungetch(char c)
{
    if(bufp >= MAXLEN)
        printf("the buf is too big.\n");
    else
        allocbuf[bufp++] = c;
}
/* --------------------- 
作者：yjysunshine 
来源：CSDN 
原文：https://blog.csdn.net/yjysunshine/article/details/82561340 
版权声明：本文为博主原创文章，转载请附上博文链接！ */
