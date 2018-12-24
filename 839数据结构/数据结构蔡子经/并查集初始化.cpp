/*
	Name: 初始化集合与合并集合 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 20:40
	Description:字段记录了集合元素个数的版本 
*/
#define MAXN 100
typedef struct node{
	int count;
	int parent;
}NODE;
NODE s[MAXN];
int n;

void init_set(NODE s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].count = 1;
		s[i].parent = -1;
	}
}

int union_set(NODE s[], int i, int j)
{
	int t;
	t = s[i].count + s[j].count;
	if (s[i].count >= s[j].count)
	{
		s[j].parent = i;
		s[i].parent = t;
		return i;
	}
	else
		{
			s[i].parent = j;
			s[j].count = t;
			return j;
		}
}

int find_set(NODE s[], int i)
{
	int j, k;
	k = i;
	while (s[k].parent>=0)
		k = s[k].parent;
	while (i != k)
		{
			j = s[i].parent;
			s[i].parent = k;
			i = j;
		}
	return k;
}
