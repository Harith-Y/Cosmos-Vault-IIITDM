#include <stdio.h>
#include<stdlib.h>
int lcm(int a, int b)
{
	if(a == b)
	{
		return a;
	}
	
	else if(a > b)
	{
		if(a % b == 0)
		{
			return a;
		}
		
		else
		{
			int k = 2;
			int temp = a;
			while(temp % b != 0)
			{
				temp = a;
				temp *= k;
				k++;
			}
			
			return temp;
		}
	}
	
	else
	{
		if(b % a == 0)
		{
			return b;
		}
		
		else
		{
			int k = 2;
			int temp = b;
			while(temp % a != 0)
			{
				temp = b;
				temp *= k;
				k++;
			}
			
			return temp;
		}
	}
}

int lcmArr(int arr[], int low, int high)
{
	if(high == low)
	{
		return lcm(arr[low], arr[low]);
	}
	
	int left = lcmArr(arr, low, (high + low)/2);
	int right = lcmArr(arr, (high + low)/2 + 1, high);
	
	return lcm(left, right);
}
int main()
{
	
	int n;
	scanf("%d",&n);
	int *arr;
	arr = (int *)malloc(sizeof( int ) * n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int l = lcmArr(arr, 0, n-1);
	printf("%d\n", l);
	return 0;
}             
