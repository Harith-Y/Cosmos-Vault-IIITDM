#include <stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
	if(a > b)
	{
		a = a - b;
	}
	else if(a < b)
	{
		b = b - a;
	}
	else
	{
		return a;
	}
	
	return gcd(a, b);
}

int gcdArr(int arr[], int low, int high)
{
	if(high == low)
	{
		return gcd(arr[low], arr[low]);
	}
	
	int left = gcdArr(arr, low, (high + low)/2);
	int right = gcdArr(arr, (high + low)/2 + 1, high);
	
	return gcd(left, right);
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
	int g = gcdArr(arr, 0,n-1);
	printf("%d\n", g);
	return 0;
}             
