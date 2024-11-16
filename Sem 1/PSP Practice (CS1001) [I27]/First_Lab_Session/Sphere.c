//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	float r,v,s;
	printf("Please enter the Radius of the Sphere\n");
	scanf("%f",&r);
	v=(4/3)*(3.1415926535897932384626433832795288)*r*r*r;
	printf("The Volume of the Sphere with given radius approximately is %f \n",v);
	s=4*(3.1415926535897932384626433832795288)*r*r;
	printf("The Surface Area of the Sphere with given radius approximately is %f \n",s);
}
