//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	float r,v,l,t;
	printf("Please enter the Radius of the Hemisphere\n");
	scanf("%f",&r);
	v=(2/3)*(3.1415926535897932384626433832795288)*r*r*r;
	printf("The Volume of the Hemisphere with given radius approximately is %f \n",v);
	l=2*(3.1415926535897932384626433832795288)*r*r;
	printf("The Lateral Surface Area of the Hemisphere with given radius approximately is %f \n",l);
	t=3*(3.1415926535897932384626433832795288)*r*r;
	printf("The Total Surface Area of the Hemisphere with given Radius approximately is %f \n",t);
}
