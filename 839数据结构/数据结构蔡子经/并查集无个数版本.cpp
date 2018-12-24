/*
	Name: 初始化集合与合并集合 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 20:40
	Description:根结点处，集合元素个数为t，则根结点的父节点指针记录为-t
	find_set函数不用改。 
*/
#define MAXN 100
typedef struct node{
	int parent;
}NODE;
NODE s[MAXN];
int n;

void init_set(NODE s[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i].parent = -1;
	}
}

int union_set(NODE s[], int i, int j)
{
	int t;
	t = s[i].parent + s[j].parent;
	if (s[i].parent <= s[j].parent)
	{
		s[j].parent = i;
		s[i].parent = t;
		return i;
	}
	else
		{
			s[i].parent = j;
			s[j].parent = t;
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
