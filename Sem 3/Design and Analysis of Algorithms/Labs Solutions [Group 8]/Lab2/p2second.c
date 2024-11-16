// GROUP-8 2ND QUESTION SECOND LOGIC
#include<stdio.h>
#include<time.h>
int missingnumber(int arr[],int n)
{
	int min;
	for(int i=0;i<n;i++)
	{
		min=arr[i];
		for(int j=i;j<n;j++)
		{
			if(arr[j]<min)
			{
				min=arr[j];
			}
		}
		if(min!=arr[i])
		{
			arr[i]=min;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		if(arr[i+1]-arr[i]==2)
		{
			return arr[i]+1;
		}
	}
	
}
int main()
{
	int n,arr[1000];
	printf("ENTER THE NO OF DIGITS\n");
	scanf("%d",&n);
	printf("ENTER THE DIGITS\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	clock_t t;
	t=clock();
	printf("THE MISSING DIGIT IS %d\n",missingnumber(arr,n));
	t=clock()-t;
	double time=((double)t)/CLOCKS_PER_SEC;
	printf("%f",time);
} 
