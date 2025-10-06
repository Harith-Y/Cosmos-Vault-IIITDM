#include <stdio.h>

int main() {
	int a[] = {1, 2, 3, 3, 5};
	float f;
	int i;
	for(i = 0; i < 5; i++)
	{
		f = f + 1*(a[i] - i);
	}
	
	printf("float: %f\n", f);
	return 0;
}

