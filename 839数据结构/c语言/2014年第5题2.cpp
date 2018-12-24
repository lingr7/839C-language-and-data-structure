/*
	Name: 读入文件hash排序写入文件 
	Copyright: 
	Author: lingr7
	Date: 16/12/18 22:04
	Description: 节省了现有答案结构体的开销 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
int hash(char *s){
	int i, sum;
	char *p;
	sum = 0;
	for(p = s; *p; p++){
		sum += i;
		if(sum > 10007)
			sum = sum % 10007;
	}
	return sum;
}
int cmp(const void *a, const void *b){
	char *p, *q;
	p = (char*)a;
	q = (char*)b;
	if(hash(p) != hash(q))
		return hash(p) - hash(q);
	else if(strlen(p) != strlen(q))
		return strlen(q) - strlen(p);
	else 
		return strcmp(q,p);
}
void Loaddata(FILE *in, char m[][MAXN]){
	int i = 0;
	while(fscanf(in, "%s", m[i]) != EOF)
		i++;
}
int main(char argc, char *argv[]){
	int i, N = atoi(argv[1]);/*命令行第一个参数*/
	char a[N][MAXN];
	FILE *fin, *fout;
	fin = fopen(argv[2], "r");
	Loaddata(fin, a);
	fclose(fin);
	qsort(a, N, sizeof(char[MAXN]), cmp);
	fout = fopen(argv[3], "w");
	for(i = 0; i < N; i++){
		fprintf(fout, "%s\n", a[i]);
	} 
	fclose(fout);
	return 0;
}
