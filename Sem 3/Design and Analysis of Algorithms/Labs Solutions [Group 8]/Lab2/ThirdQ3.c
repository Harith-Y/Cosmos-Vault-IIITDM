#include<stdio.h>
#include<time.h>
void sort(int arr[], int size, int output[])
{
 int j=0;
 for(int i=0; i<size; i++)
 {
  if(arr[i]==0)
  {
   output[j++] = 0;
  }
 }
 for(int i=0; i<size; i++)
 {
  if(arr[i]==1)
  {
   output[j++] = 1;
  }
 }
 for(int i=0; i<size; i++)
 {
  if(arr[i]==2)
  {
   output[j++] = 2;
  }
 }
}
void main()
{
 int size;
 printf("Size: ");
 scanf("%d", &size);
 int arr[size];
 int output[size];
 printf("Enter an array of only 0s,1s and 2s: \n");
 for(int i=0; i<size; i++)
 {
  scanf("%d", &arr[i]);
 }
 clock_t t; 
 t = clock(); 
 sort(arr, size, output);
 for(int i=0; i<size; i++)
 {
  printf("%d ", output[i]);
 }
 t = clock() - t; 
 double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
 printf("fun() took %f seconds to execute \n", time_taken); 
}
