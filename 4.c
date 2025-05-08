//djikstras
#include<stdio.h>
int n,cost[10][10],dist[10];
int min(int a,int b);
void read_mat(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			printf("(%d,%d)",i,j);
			scanf("%d",&cost[i][j]);
		}
}

void shortestpath(int n,int s)
{
	int vis[10],c,u,i,k;
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
		dist[i]=cost[s][i];
	}
	dist[s]=0;
	vis[s]=1;
	for(k=1;k<=n;k++)
	{
		c=999;
		for(i=1;i<=n;i++)
		if(vis[i]==0)
		{
			if(dist[i]<=c)
			{
				c=dist[i];
				u=i;
			}
		}
		vis[u]=1;
		for(i=1;i<=n;i++)
		dist[i]=min(dist[i],(dist[u]+cost[u][i]));
	}
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void main()
{
	int i,j,s;
	printf("enter the num of vertices\n");
	scanf("%d",&n);
	printf("enter the costadjacency matrix(999 for no edge);\n");
	read_mat(n);
	printf("enter source vertex\n");
	scanf("%d",&s);
	shortestpath(n,s);
	printf("the shortest path b/n vertex %d to",s);
	for(i=1;i<=n;i++)
		printf("vertex %d is %d\n",i,dist[i]);
}
