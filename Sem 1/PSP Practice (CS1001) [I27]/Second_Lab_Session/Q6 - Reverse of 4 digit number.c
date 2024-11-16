//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a,T,h,t,u,s,r;
	printf("Please enter a 4 digit number\n");
	scanf("%d",&a);
	T = a/1000;
	h = (a-(1000*T))/100;
	t = (a-(1000*T)-(100*h))/10;
	u = (a-(1000*T)-(100*h)-(10*t));
	s=T+h+t+u;
	r=(1000*u)+(100*t)+(10*h)+(1*T);
	printf("The sum of the digits of the given number is %d\n",s);
	printf("The Reverse number is %d\n",r);

}
