// 可用于解2017最后一题即为找简单路径，没有回路
// uv:指定的两点 path用于存放路径的数组 d迭代的路径深度 k指定的长度
void FindPath(ALGraph * algraph,int u,int v,int path[],int d,int k){
    int w;
    ArcNode * p;
    d++;
    path[d] = u;/*path记录从v出发经历的结点*/
    visited[u] = 1;
    if(u==v){/*此处为递归出口，从v出发寻找u, 这一趟v走到了终点*/
        if(d==k){/*如果到终点的步数为k,那么输出该路径*/
            printPath(path, d);
        }
        visited[v] = 0;
        return;
    }
    p = algraph->vertices[u].first;/*邻接表中u对应的头指针*/
    while(p!=NULL){/*进行dfs遍历*/
        w = p->adjvex;
        if(visited[w] == 0){
            FindPath(algraph,w,v,path,d,k);
        }
        p = p->next;
    }
    visited[u] = 0;/*为什么要恢复呢？*/
}

void findpath(ALGraph &G, int v, int u, int k, , int d,int flag) { //(v,u) 
	visited[v] = 1; 
	d++; 
	if (u == v) 
		if (d == k) 
			flag = 1;//符合条件返回1 
	for(int w = FirstNeighbor(G, v); w > 0; w = NextNeighbor(G, v, w)) { 
		if (!visited[w]) 
			findpath(G, w, u, k, d,flag); //flag==1 说明有该路径 
	} 
	visited[v] = 0; //重置为未访问。 
} 
