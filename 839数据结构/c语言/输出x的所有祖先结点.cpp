/*
	Name: 输出x的所有祖先结点 
	Copyright: 
	Author: 11楼 
	Date: 15/12/18 20:00
	Description: 我做了一定修改 
*/
typedef struct Tree {
	int data;
	Tree *lchild;
	Tree *rchild;
}Tree;

int IsAnce(Tree *t,int x) {
	if (t) {
		if (t->data == x)
			return 1;
		else
			return IsAnce(t->lchild, x) || IsAnce(t->rchild, x);
	}
	return 0;
}

void OutX(Tree *t,int x) {
	if (IsAnce(t,x))
		printf("%d", t->data);/*这一句是递归出口*/
	OutX(t->lchild, x);
	OutX(t->rchild, x);
}
