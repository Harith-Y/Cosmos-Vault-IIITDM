#include<stdio.h>
#include<stdlib.h>

void main()
{
	int a[12], b, c=100,i;
	int *m;
	for(i=0;i<12;i++)
	{
		a[i+1]=i+1;
		b=a[i]+c;
	}
	m=(int *) malloc(4);
	*m=90;
	printf("%d", b);
}
