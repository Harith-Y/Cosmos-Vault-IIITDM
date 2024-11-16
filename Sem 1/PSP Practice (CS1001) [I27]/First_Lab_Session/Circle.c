//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	float r,a,p;
	printf("Please enter the Radius of the Circle\n");
	scanf("%f",&r);
	a=(3.141592653589793238462643383279528869279)*r*r;
	p=2*(3.141592653589793238462643383279528869279)*r;
	printf("The Area of the Circle with given Radius is %f \n",a);
	printf("The Perimeter of the Circle with given Radius is %f \n",p);
}
