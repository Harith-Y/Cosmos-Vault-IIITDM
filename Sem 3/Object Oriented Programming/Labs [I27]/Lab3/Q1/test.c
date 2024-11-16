#include <stdio.h>

int a = 0;
void main() {
	printf("Hello %d \n", a);
	a++;
	if (a < 3)
		main();
	printf("World %d \n", a);
}

