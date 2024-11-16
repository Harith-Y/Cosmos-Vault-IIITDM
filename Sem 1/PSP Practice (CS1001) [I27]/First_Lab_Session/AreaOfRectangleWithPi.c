//Harith Y (B2), CS23I1027
#include<stdio.h>
#include<math.h>
void main()
{
	int a,b,c,d;
	printf("Please enter the Length of the Rectangle\n");
	scanf("%d",&a);
	printf("Please enter the Breadth of the Rectangle\n");
	scanf("%d",&b);
	c=pow(a,b);
	d=2*pi;
	printf("%d \n",d);
	printf("The Area of the Rectangle with given dimensions is %d \n",c);
}
