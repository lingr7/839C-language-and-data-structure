/*
	Name: 统计c语言关键字出现次数 
	Copyright: 
	Author: lingr7
	Date: 21/10/18 10:05
	Description: 完全根据《C程序设计语言》K&R版本6.3结构数组内容编写。在dev c++5.11中编译运行成功
	一个项目文件.dev,内含calc.h,getch.c,getop.c,keytab.h,stack.c,tongjimain.c.5个子文件 
	关键字结构数组在keytab.h中定义，可以自行修改该表，弹药注意，这个数组里顺序必须是字典序升序。 
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "calc.h"
#include "keytab.h"

#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);
/*统计输入中c语言关键字的出现次数*/
main(){
	int n;
	char word[MAXWORD];
	printf("%s %s %s", keytab[0].word, keytab[1].word, keytab[2].word);
	while (getword(word,MAXWORD) != EOF)/*因为EOF而不易调试*/
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
				keytab[n].count, keytab[n].word);
	return 0;
} 
/*折半查找*/
/*2018年10月20日
lingr7*/
/* binsearch函数 ：在tab[0]到tab[n-1]中查找单词 */
int binsearch(char *word, struct key tab[], int n){
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (high+low) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else 	/*找到了匹配的值*/
			return mid; 
	}
	return -1;	/*没有匹配的值*/
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
