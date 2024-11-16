//Calculate the sum of all elements in a array using pointers
#include<stdio.h>
void main()
{
	int length;
	printf("Please enter the number of elements in the array : ");
	scanf(" %d",&length);
	int arr[length];
	
	printf("Enter the elements in the Array : \n");
	for (int i=0;i<length;i++)
		scanf(" %d",&arr[i]);
	
	int sum=0;		
	int *adder;
	adder=&sum;
	for (int i=0;i<length;i++)
	{
		*adder=*adder+arr[i];		
	}

	printf("The sum of all the elements in the given array is : %d\n",*adder);

}
