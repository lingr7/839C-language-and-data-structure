/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/12/18 21:08
	Description: 
*/
#include <stdio.h>

char a[20];
int index[20];
void solve(int n, int m, int level)
{
	int i;
	if(m == level)
	{
		for(i = 0; i < m; i++)
			printf("%c", a[index[i]]);
		printf("\n");
	}
	else{
		for(i = index[level-1] + 1; i < n; i++)
		{
			index[level] = i;
			solve(n, m, level+1);
		}
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", a);
	int i;
	for (i = 0; i < n; i++)
	{
		index[0] = i;
		solve(n, m, 1);
	}
	return 0;
} 
