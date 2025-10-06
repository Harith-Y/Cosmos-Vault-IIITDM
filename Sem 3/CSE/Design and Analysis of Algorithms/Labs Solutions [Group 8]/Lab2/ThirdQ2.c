//GROUP 8 - QUESTION 3 - LOGIC 2 (BUBBLE SORT)
#include<stdio.h>
#include<time.h>
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
void sort(int arr[], int size)
{
 for(int i=0; i<size-1; i++)
 {
  for(int j=0; j<size-i-1; j++)
  {
   if(arr[j]>arr[j+1])
   {
    swap(&arr[j], &arr[j+1]);
   }
  }
 }
}
void main()
{
 int size;
 printf("Size: ");
 scanf("%d", &size);
 int arr[size];
 printf("Enter an array of only 0s,1s and 2s: \n");
 for(int i=0; i<size; i++)
 {
  scanf("%d", &arr[i]);
 }
 clock_t t; 
 t = clock(); 
 sort(arr, size);
 for(int i=0; i<size; i++)
 {
  printf("%d ", arr[i]);
 }
 t = clock() - t; 
 double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
 printf("fun() took %f seconds to execute \n", time_taken); 
}
