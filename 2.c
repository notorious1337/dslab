//quicksort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 500000
int partition(int a[],int low,int high);
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return temp;
}

void quicksort(int a[],int low,int high)
{
	int s;
	if(low<high)
	{
		s=partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);
	}
}


int partition(int a[],int low,int high)
{
	int  i,j,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while((i<high)&&(pivot>=a[i]))
		i++;
		while(pivot<a[j])
		j--;
		if(i<j)
		{
			swap(&a[i],&a[j]);
		}
		else
		{
			swap(&a[low],&a[j]);
				       return j;
		}
	}
}


void main()
{
 	int a[MAX],n,i,low,high;
  	clock_t start,end;
     	float duration;
     	printf("\n enter the number of elements to sort");
     	scanf("%d", &n);
     	printf("\n  elements are:\n");
     	for(i=0;i<n;i++)
     	{
     		//scanf("%d",&a[i]);
     		a[i]=random();
		printf("Before Sorting\n");
     		printf("%d\t",a[i]);
     	}
     	printf("\n");
     	start=clock();
     	low=0,high=n-1;
     	quicksort(a,low,high);
     	end=clock();
     	duration=(end-start);
     	printf("\n sorted array is::\n");
     	for(i=0;i<n;i++)
     		printf("\n\t%d",a[i]);
     	printf("\n");
     	printf("time taken is %f",duration);
}

