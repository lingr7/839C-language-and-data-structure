/*
	Name: 将叶子节点转为带有表头结点的单链表 
	Copyright: 
	Author: 
	Date: 14/12/18 18:57
	Description: 采用层序遍历，先将叶子节点存入一个数组中，再将其改造成单链表 
*/
struct TreeNode{
	char data;
	struct TreeNode *lchild;
	struct TreeNode *rchild;
};
typedef struct TreeNode Node;
Node *Find(Node *t)
{
	int head,tail,i,j;
	Node *q[100], *leaves[100], *p;
	i = 0;
	head = 0;
	tail = 1;
	q[head] = t;
	while(head < tail)
	{
		p = q[head++];
		if(p->lchild != NULL)
			q[tail++] = p->lchild;
		if(p->rchild != NULL)
			q[tail++] = p->rchild;
		if(p->lchild == NULL && p->lchild == NULL)
			leaves[i++] = p;
	}	
	while(--i){
		leaves[i-1]->rchild = leaves[i];
	}
	Node *LeafHead;
	LeafHead = (Node*)malloc(sizeof(Node));
	LeafHead =leaves[0];
	return LeadHead; 
} 
