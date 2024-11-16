#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
int main()
{
 int n = 5;
 int arr[n][2];
 int sum=0;
 for(int i = 0; i < n; i++)
 {
        arr[i][0] = rand()%10;
        arr[i][1] = rand()%10;
 }
 //printing arrays
 for(int i=0; i<n; i++)
 {
  cout << arr[i][0] << " " << arr[i][1] << endl;
 }
 for(int i=0; i<n-1; i++) //bubble sort implementation
 {
  for(int j=0; j<n-i-1; j++)
  {
		int s1=0;
		int s2=0;
		s1 = abs(arr[j][0]-arr[j][1]) + abs(arr[j+1][0]-arr[j+1][1]);
		s2 = abs(arr[j][0]-arr[j+1][1]) + abs(arr[j+1][0]-arr[j][1]);
		if(s2<s1)
		{
		 swap(&arr[j][1], &arr[j+1][1]);
		}
	}
 }
 for(int i=0; i<n-1; i++)
 {
  sum+=abs(arr[i][0] - arr[i][1]);
 }
 cout << endl;
 cout << "Minimised sum: " << sum << endl;
 //printing arrays
 for(int i=0; i<n; i++)
 {
  cout << arr[i][0] << " " << arr[i][1] << endl;
 }
 return 0;
}
