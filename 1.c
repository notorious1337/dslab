//mergesort
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<time.h>
#define MAX 300000
void simple_merge(int a[],int low,int mid,int high);
void merge_sort(int a[],int low,int high);
int n;
int main( )
{
	int a[MAX],i=0;
	double startTime,endTime;
	printf("Enter the number of elements to sort\n");
	scanf("%d",&n);
	//To generate randomly
	for(i=0;i<n;i++)
		a[i]=rand();
	printf("\nBefore Sorting:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
	startTime=clock();
	merge_sort(a,0,n-1);
	endTime = clock();
	printf("After Sorting:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	printf("Time taken is %10.9f\n",(double)(endTime-startTime));
	return 0;
}

/*Function to sort sub arrays elements*/
void simple_merge(int a[],int low,int mid,int high)
{
	int i=low,j=mid+1,k=low,c[MAX];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			i++;
			k++;
		}
		else
		{
			c[k]=a[j];
			j++;
			k++;
		}
	}
	while(i<=mid)
		c[k++]=a[i++];
	while(j<=high)
		c[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=c[i];
}


/*Function to divide the array list */
void merge_sort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		{
			merge_sort(a,low,mid);
			merge_sort(a,mid+1,high);
		}
	simple_merge(a,low,mid,high);
	}
}
