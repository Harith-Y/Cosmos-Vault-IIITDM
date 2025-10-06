// GROUP-8 2ND QUESTION FIRST LOGIC
#include<stdio.h>
#include<time.h>
int missingnumber(int arr[],int n)
{
	int final[1000]={0};
	for(int i=0;i<n;i++)
	{
		final[arr[i]-1]++;
	}
	for(int i=0;i<n;i++)
	{
		if(final[i]==0)
		{
			return i+1;
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
