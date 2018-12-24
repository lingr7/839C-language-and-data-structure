/*
	Name: 标准二叉树是否满足堆条件 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 16:34
	Description: 首先将标准存储的二叉树，通过层序遍历转化为堆常用的一维数组形式，这里以最大堆为例。
	 有n个结点的二叉树。接下里以下标0位根结点，发生了位置调整则不满足堆的条件，未经调整则满足堆的条件，以k为标记，
	 若返回值k为1，则不满足最大堆条件，为0则满足最大堆条件 
	2017年的第九题，有一个版本的题目答案正是这个思路，将一个没做过的问题变成一个做过的问题，考场上能写出来也值了。 
*/	 
struct TreeNode{
	int data;
	Node *lchild;
	Node *rchild;
};
typedef TreeNode Node;
int Judge_Heap(Node *t, int n)
{
	int heap[100];
	int head;
	int tail;
	int i;
	Node *p, *q[100];
	q[0] = t;
	head = 0;
	tail = 1;
	i = 0;
	heap[0] = t->data;
	while(head < tail){
		p = q[++head];
		if(p->lchild != NULL){
			q[++tail] = p->lchild;
			heap[++i] = p->lchild->data;
		}	
		if(p->rchild != NULL){
			q[++tail] = p->rchild; 
			heap[++i] = p->rchild->data;
		}	
	}
	i = 0;
	int j, k;
	k = 0;
	t = a[i];
	while((j = 2*i +1) < n){
		if (j < n-1 && a[j] < a[j+1])
			j++;
		if (t < a[j]){
			a[(j-1)/2] = a[j];
			i = j;
			k = 1;
		}
		else break;
	}
	a[(j-1)/2] = t;
	return k;
}
/*更好的答案，并且注意到判断是否完全二叉树，但我觉得堆并非必须是完全二叉树啊*/
int estimate_stack(Node *t,int *n)
{
	int a = 1,b = 1;//标志位
	int n1 = 0,n2 = 0;
	if(t)
    {
//如果存在左子树，先判断值是否满足条件，如果满足再递归判断左子树是否满足条件。将最终的结果&&起来
		if(t->lc)
			a = (t->data >= t->lc->data) && estimate_stack(t->lc,&n1);
//如果左子树已经不满足了，不用继续递归右子树了
        if(t->rc && a)
			b = (t->data >= t->rc->data) && estimate_stack(t->rc,&n2);
//如果左子树结点数比右子树结点数少，则不是完全二叉树 
        if(n1 < n2)
			a = b = 0;
//左右子树加1为自己当前的节点个数
        *n = n1 + n2 + 1;
	}
	else
		*n = 0;
//如果为空，则表示这个节点满足定义
    return a && b;
}
/*简化版本也就是最终版本*/
int estimate_stack(Node *t)
{
	int a = 1,b = 1;//标志位
	if(t)
    {
//如果存在左子树，先判断值是否满足条件，如果满足再递归判断左子树是否满足条件。将最终的结果&&起来
		if(t->lc)
			a = (t->data >= t->lc->data) && estimate_stack(t->lc);
//如果左子树已经不满足了，不用继续递归右子树了
        if(t->rc && a)
			b = (t->data >= t->rc->data) && estimate_stack(t->rc);
	}
//如果为空，则表示这个节点满足定义
    return a && b;
}
