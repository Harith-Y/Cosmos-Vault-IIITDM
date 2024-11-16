//GROUP 8 - QUESTION 3 - LOGIC 1 
#include<stdio.h>
#include <time.h>
void sort(int arr[], int size)
{
 int t_arr[3] = {0};
 for(int i=0; i<size; i++)
 {
  if(arr[i]==0)
  {
   t_arr[0]++;
  }
  else if(arr[i]==1)
  {
   t_arr[1]++;
  }
  else if(arr[i]==2)
  {
   t_arr[2]++;
  }
 }
 int j=0;
 for(int i=0; i<3; i++)
 {
  while(t_arr[i]!=0)
  {
   arr[j++] = i;
   t_arr[i]--;
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