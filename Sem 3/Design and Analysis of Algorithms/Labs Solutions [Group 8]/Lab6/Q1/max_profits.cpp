//Aim: to pack maximum profits as possible
#include<string>
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}
int main()
{
    ifstream inputFile("s1000.kp");
    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;
    cout << "File Content: " << endl;
    getline(inputFile, line);
    int n = stoi(line);
    getline(inputFile, line);
    int c = stoi(line);
    int objects[n][2];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < 2; j++)
        inputFile >> objects[i][j];
    inputFile.close();
 for(int i=0; i<n; i++) //bubble sort implementation
 {
  for(int j=0; j<n-i-1; j++)
  {
   if(objects[j][0]<objects[j+1][0])
   {
    swap(&objects[j][1], &objects[j+1][1]);
    swap(&objects[j][0], &objects[j+1][0]);
   }
  }
 }
 int sum=0;
 int max_profits=0;
 int i=0;
 for(; i<n; i++)
 {
  if(sum+objects[i][1] <=c)
  {
   max_profits+=objects[i][0];
   sum+=objects[i][1];
  }
 }
 cout << "Max Profit: " << max_profits << endl;
 /*for(int i=0; i<n; i++)
 {
  printf("[%d][%d] ", objects[i][0], objects[i][1]);
 }*/
 return 0;
}
