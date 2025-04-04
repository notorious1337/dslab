#include<stdio.h>
void main()
{
int 
n,v,u,cost[10][10],parent[10]={0},i,j;
int count=1,mincost=0,min,a,b;
printf("\n enter no of vertices");
scanf("%d",&n);
printf("\n enter cost matrix");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
while(count<n)
{    min=999;
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
while(parent[u])
u=parent[u];
while(parent[v])
v=parent[v];
if(u!=v)
{
count++;
printf("\n edge(%d,%d)=%d",a,b,min);
mincost+=min;
parent[v]=u;
}
cost[a][b]=cost[b][a]=999;
}  /*End of While */
printf("\n minimum cost=%d",mincost);
}
