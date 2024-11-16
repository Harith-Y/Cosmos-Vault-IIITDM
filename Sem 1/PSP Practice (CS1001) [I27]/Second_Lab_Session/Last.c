//Harith Y (B2), CS23I1027
#include<stdio.h>
void main()
{
	int a,b,postinc,preinc,postdec,preinc;
	
	printf("For Post Increment of a number, Press 1");
	printf("For Pre Increment of a number, Press 2");
	printf("For Post Decrement of a number, Press 3");
	printf("For Pre Deccrement of a number, Press 4");
	scanf("%d",&b);
	
	if (b==1)
	{
	printf("Please enter a number\n");
	scanf("%d",&a);
	postinc = a++;
	printf("The Post Increment is %d\n",postinc);
	}
	
	else if (b==2)
	{
	printf("Please enter a number\n");
	scanf("%d",&a);
	preinc = ++a;
	printf("The Pre Increment is %d\n",preinc);
	}
	
	else if (b==3)
	{
	printf("Please enter a number\n");
	scanf("%d",&a);
	postdec = a--;
	printf("The Post Decrement is %d\n",postdec);
	}
	
	else if (b==4)
	{
	printf("Please enter a number\n");
	scanf("%d",&a);
	predec = --a;
	printf("The Pre Decrement is %d\n",predec);
	}
	
	else
	{
	printf("Invalid Input")
	}
}
