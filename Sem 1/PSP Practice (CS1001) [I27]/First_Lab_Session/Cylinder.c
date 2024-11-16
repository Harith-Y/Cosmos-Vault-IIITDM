//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	float r,h,v,l,t;
	printf("Please enter the Height of the Right Cylinder\n");
	scanf("%f",&h);
	printf("Please enter the Radius of the base of the Right Cylinder\n");
	scanf("%f",&r);
	v=(3.1415926535897932384626433832795288)*r*r*h;
	printf("The Volume of the Right Cylinder with given dimensions approximately is %f \n",v);
	l=2*(3.1415926535897932384626433832795288)*r*h;
	printf("The Lateral Surface Area of the Right Cylinder with given dimensions approximately is %f \n",l);
	t=2*(3.1415926535897932384626433832795288)*r*(r+h);
	printf("The Total Surface Area of the Right Cylinder with given dimensions approximately is %f \n",t);
}
