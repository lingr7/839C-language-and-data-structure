/*
	Name: Prim算法 
	Copyright: 
	Author: lingr7
	Date: 24/10/18 08:10
	Description: 2018年20分题，最小生成树 
*/
/* 1 <= vertex number <=n <MAXN */

#define MAXINT 9999
#define MAXN 100
int mat[MAXN][MAXN];
int n,u;

void prim(cost, n, u){
	int cost[][MAXN];
	int n, u;
	{
		int lowest[MAXN],min;
		int closest[MAXN];
		int i, j, k;
		for (i = 1; i <= n; i++){
			lowest[i] = cost[u][i];
			closet[i] = u;
		}
		for(i = 1; i < n ;i++){
			min = MAXINT;
			for (j = 1; j <= n; j++){
				if(lowcost[j] != 0 && lowcost[j] < min){
					min = lowcost[j];
					k = j;
				}
			}
			printf("{%3d%3d%5d} ", closest[k], k, cost[closest[k]][k]);
			lowcost[k] = 0;
			for (j = 1; j <= n; j++){
				if(cost[k][j] != 0 && cost[k][j] < lowcost[j]){
					lowcost[j] = cost[k][j];
					closest[j] = k;
				}
			}
		}	
	}
}
