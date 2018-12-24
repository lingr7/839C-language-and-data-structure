/*
	Name: 统计关键字出现次数，使用指针实现的版本 
	Copyright: 
	Author: ligr7
	Date: 04/11/18 17:29
	Description: 
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

int getword(char *, int);
struct key *binsearch(char *, struct key *,int);

/* 统计关键字出现的次数；采用指针方式实现的版本 */
main(){
	char word[MAXWORD];
	struct key *p;
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])
			if (isalpha(word[0])) 
				if ((p=binsearch(word, keytab, NKEYS)) != NULL)
					p->count++;
	for (p = keytab; p < keytab + NKEYS; p++){
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
} 
/* binsearch函数：在tab[0]...tab[n-1]中查找与读入单词匹配的元素 */
struct key *binsearch(char *word, struct key *tab, int n){
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;
	
	while (low < high) {
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return NULL;
} 
