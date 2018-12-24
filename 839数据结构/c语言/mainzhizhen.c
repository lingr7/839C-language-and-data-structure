/*
	Name: 统计关键字的出现次数：采用指针实现的版本 
	Copyright: 
	Author: lingr7
	Date: 04/11/18 19:00
	Description: 指向结构的指针 
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "keytab.h"
#include "calc.h"
#define MAXWORD 100

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int getword(char *, int);
struct key *binsearch(char *, struct key *,int);

/* 统计关键字出现的次数；采用指针方式实现的版本 */
int main(int argc, char *argv[]) {
	char word[MAXWORD];
	struct key *p;
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) 
			if ((p = binsearch(word, keytab, NKEYS)) != NULL)/*keytab是个结构体指针*/ 
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}
/* getword函数：从输入中读取下一个单词或字符*/
int getword(char *word, int lim){
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);/**/ 
            break;
        }
    *w = '\0';
    return word[0];
} 
/* binsearch函数：在tab[0]...tab[n-1]中查找与读入单词匹配的元素 */
struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];/*这里不用取地址符，则右边直接为tab */
	struct key *high = &tab[n];/*这里如不用取地址符，则是tab+n */
	struct key *mid;
	
	while (low < high) {
		mid = low + (high - low) / 2;/*通过指针减法得到一个数，再用指针加上一个数*/
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return NULL;
}
