//floyds
#include<stdio.h>
#include<time.h>
#define INFINITY 999
int min(int a,int b)
{
	return a<b?a:b;
}

void floyd(int w[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
}

int main(void)
{
	int a[10][10],n,i,j;
	double startTime,endTime;
	printf("\n Enter the no. of vertices:");
	scanf("%d",&n);
	printf("\n Enter the cost matrix, 0-self loop and 999-no edge\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	startTime=clock();
	floyd(a,n);
	endTime =clock();
	printf("\n Shortest path matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("Time taken is %10.9f\n",(double)(endTime-startTime));
	return 0;
}	
