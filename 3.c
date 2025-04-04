#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 300000
int n;
int main()
{
int a[MAX];
double startTime,endTime;
int i,j,temp,min;
printf("Enter the number of elements to sort\n");
scanf("%d",&n);
//To generate numbers randomly and store in array
for(i=0;i<n;i++)
a[i]=rand(); //rand() function to generate n random numbers
printf("\nBefore Sorting:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
startTime=clock();
for(i=0;i<=n-2;i++)
{
min=i;
for(j=i+1;j<=n-1;j++)
{
if(a[j]<a[min])
min=j;
}
temp=a[min];
a[min]=a[i];
a[i]=temp;
}
endTime = clock();
printf("After Sorting:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
printf("Time taken is %10.9f\n",(double)(endTime-startTime));
return 0;
}
