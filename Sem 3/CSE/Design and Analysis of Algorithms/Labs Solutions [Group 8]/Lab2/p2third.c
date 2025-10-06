// GROUP-8 2ND QUESTION THIRD LOGIC
#include<stdio.h>
#include<time.h>
int missingnumber(int arr[],int n)
{
	int sumofn,sumofarr=0;
	sumofn=(n*(n+1))/2;
	for(int i=0;i<n;i++)
	{
		sumofarr +=arr[i];
	}
	int missing;
	missing=sumofn-sumofarr;
	if(missing<0)
	{
		missing=missing*(-1);
	}
	return missing;
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
