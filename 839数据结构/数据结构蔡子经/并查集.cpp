/*
	Name: 用树表示集合find应用折叠规则 
	Copyright: 
	Author: 
	Date: 14/11/18 19:39
	Description: 折叠规则，路径压缩，循环
	先找到根结点，然后把路径上经过的结点，全部指向根结点，即全部的父节点为根结点 
*/

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
