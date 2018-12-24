/*
	Name: 邻接矩阵Prim算法 
	Copyright: 
	Author: 
	Date: 10/12/18 22:44
	Description: 
*/
#define MAXINT 9999
#define MAXN 100
int mat[MAXN][MAXN]
int n, u;

void prim(int cost[][MAXN], int n, int u)
{
	int lowcost[MAXN], min;
	int closest[MAXN];
	int i, j, k;
	for (i = 1; i<=n; i++)
	{
		lowcost[i] = cost[u][i];/*将顶点u的到各顶点距离存入*/
		closest[i] = u;
	}	
		
	for (i = 1; i<n; i++)
	{
		min = MAXINT;
		/*找到最短的一条边*/
		for(j = 1; j <=n; j++)
			if(lowcost[j]!=0&&
			lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
			
		printf("{%3d%3d%5d}  ",
				closest[k], k,
				cost[closet[k]][k]);
				
		lowcost[k] = 0;/*置零代表这个顶点已经*/
		for(j = 1;j<=n;j++)
			if(cost[k][j] != 0&&
				cost[k][j] < lowcost[j])
				{
					lowcost[j] = cost[k][j];
					closet[j] = k;
				}
	}
} 
