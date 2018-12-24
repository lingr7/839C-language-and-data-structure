#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000


struct stuInfo
{
	char *ID;
	char *name;
	int score;
};/* 这个地方的分号注意*/
typedef struct stuInfo stuType; 

int cmp(const void*a, const void *b)
{
	return atoi(((stuType*)a)->ID) - atoi(((stuType*)b)->ID);/*注意->的优先级太高容易出现的问题*/
}

int main(char argc, char *argv[])
{
	stuType stu[MAX];
	
	FILE *fin, *fout;
	fin = fopen(argv[1], "r");
	
	int i = 0;
	while(fscanf(fin, "%s", stu[i].ID) == 1)
	{
		fscanf(fin, "%s", stu[i].name);
		fscanf(fin, "%d", stu[i].score);
		i++;
	}
	fclose(fin);
	
	int N = i; 
	int M = N/100;
	
	stuType selectedStu[M];
	int selectedList[M];
	int cnt = 0; 
	int remaining = M;
	
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		if(rand() % (N - i) < remaining)
		{
			selectedList[cnt++] = i;
			remaining--;
		}
	}
	for (i = 0; i < M; i++)
	{
		selectedStu[i] = stu[selectedList[i]];
	}
	qsort(selectedStu, M, sizeof(selectedstu[0]), cmp);
	
	fout = fopen(argv[2], "w");
	for (i = 0; i < M; i++)
	{
		fprintf(fout, "%s %s %d\n", selectedStu[i].ID,
		selectedStu[i].name, selectedStu[i].score);
	}
	fclose(fout);

	return 0;
}
