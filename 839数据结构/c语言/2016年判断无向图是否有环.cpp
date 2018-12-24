/*
	Name: 判断无向图是否有环 
	Copyright: 
	Author: lingr7
	Date: 15/12/18 10:34
	Description: 借用拓扑序列思想 ，如果i==n那么该无向图中无环 
	不断寻找度为1的结点 
*/
struct CH_NODE{
	int count;
	struct CH_NODE *head;
};
struct VL_NODE{
	int ver;
	struct VL_NODE *link;
};
CH_NODE ch[6];/*下标1-5记录5个顶点的头指针*/
int tpv[100];/*记录输出顶点*/
int topol_order(CH_NODE ch[5], int n, int tpv[]){
	int i, j, k, head, tail;
	VL_NODE *t;
	head = -1;
	tail = -1;
	int queue[100];/*队列*/
	for(i = 1; i <= n; i++){
		if(ch[i].count == 1)
			queue[++tail] = i;/*度为1的顶点入队*/
	}
	i = 0;
	while(head < tail)/*队列不空*/{
		j = queue[++head];/*出队*/
		tpv[i++] = j;
		t = ch[j].head;
		while(t != NULL){
			k = t->ver;
			if(--(ch[k].count) == 1)
				queue[++tail] = k; 
			t = t->link;
		} 
	}
	return i;/*i记录了曾经入队的顶点数目*/
} 
 
