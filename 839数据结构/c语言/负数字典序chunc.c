/*
	Name: 
	Copyright: 
	Author: 
	Date: 01/12/18 11:36
	Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare1(const void *a, const void *b)
{
	return atoi((char*)b) - atoi(*(char(*)[80])a);/*这里将b转换为一个指向字符数组的指针，该字符数组有80个元素*/
}
int compare2(const void *a, const void *b)
{
	/*char (*x)[80] = a, (*y)[80] = b;
	/*char *x = *(char(*)[80])a;/*右端确认是记录了一个字符数组的第一个元素的地址，下标为0*/
	char *x = a;
	char *y = *(char(*)[80])b;
	int diff = strlen(x) - strlen(y);
	return diff ? diff : strcmp(x, y);
}
int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[1], "r");
	/*FILE *fp = fopen("data", "r");*/
	char a[100][80];
	int i, cnt = 0;
	while (fscanf(fp, "%s", a[cnt]) == 1)
		printf("%s ", a[cnt++]);
	printf("\n");
	qsort(a, cnt, sizeof(char[80]), compare1);
	for( i = 0; i < cnt; i++)
		printf("%s ", a[i]);
	printf("\n");
	qsort(a, cnt, sizeof(char[80]), compare2);
	for( i = 0; i < cnt; i++)
		printf("%s ", a[i]);
	printf("\n");
}
