/*
	Name: 链接栈中序遍历二叉树 
	Copyright: 
	Author: lingr7
	Date: 19/11/18 13:52
	Description: 修正一处蔡子经的错误 
*/
#include<stdio.h>
struct node{
	char data;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node NODE;
struct snode {
	NODE *addr;
	struct snode *link;
};
typedef struct snode SNODE;

void s_midorder(NODE *t){
	SNODE *top, *p;
	top = NULL;
	while(t!=NULL || top != NULL)
	{
		while (t != NULL || top != NULL){
			p = (SNODE*)malloc(sizeof(SNODE));
			p->addr = t;
			p->link = top;
			top = p;
			t = t->lchild;	
		}
		/*if (top != NULL){ 修正处*/
		if (top != NULL && t == NULL){
			t = top->addr;
			printf("%c", t->data);
			p = top;
			top = top->link;
			free(p);
			t = t->rchild;
		}
	}
}

