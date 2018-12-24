/*
	Name: 前序遍历递归版本 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:09
	Description: 这里似乎默认m次树，根结点就有m棵子树 
*/
#include <stdio.h>
#define MAXM 10
struct node {
	char data;
	struct node *child[MAXM];
};
typedef struct node NODE;
int m;
NODE *t;

/*递归函数实现对给定的m次树的前序遍历*/
void r_preorder(NODE *t, int m)
{
	int i;
	if (t != NULL)
		{
			printf("%c", t->data);
			for (i = 0; i < m; i++)
				r_preorder(t->child[i]);
		}
}
