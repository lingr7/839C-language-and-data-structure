/*
	Name: 前序遍历堆栈版本 
	Copyright: 
	Author: lingr7
	Date: 14/11/18 21:11
	Description: 实现前序遍历，用栈来实现递归的效果。
	使用顺序存储的栈s[100],栈顶指针是top,栈元素最多是100个，
	假设不会出现栈溢出的情况。 
*/
void s_preorder(NODE *t, int m)
{
	NODE *s[100];
	int top, i;
	if (t == NULL)
		return;
	s[0] = t;
	top = 1;
	while (top > 0)
	{
		t = s[--top];
		printf("%c", t->data);
		for(i = m-1; i>=0; i--)
		{
			if (t->child[i] != NULL)
				s[top++] = t->child[i];
		}
	 } 
}
