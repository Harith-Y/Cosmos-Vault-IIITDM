#include<stdio.h>
int recurse(int i)
{
  if(i==0)
       return 0;
  else
       recurse(i-1);
}
int main()
{
       int i = 8;
       recurse(i);
}
