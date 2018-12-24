/*
	Name: 层次遍历给定的m次树 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:40
	Description: 使用顺序存储的队列存放还没有处理的子树的根结点的地址。
	假设树中的结点值是字符，按标准形式存储给定的树。
	这里假设所使用的队列不会出现队列溢出的情况。
	注意，这里的队首和队尾指针分别指向队首结点和下次进队结点的存放位置。 
*/
void levorder(NODE *t, int m)
{
	NODE *q[100], *p;
	int head, tail, i;
	q[0] = t;
	head = 0;
	tail = 1;
	while (head < tail)
	{
		p = q[head+1];
		printf("%c", p->data);
		for (i = 0; i < m; i++)
		{
			if (p->child[i] != NULL)
				q[tail++] = p->child[i]; 
		} 
	}
}
