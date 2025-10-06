#include <stdio.h>
void tower_Of_hanoi(int n, char from_rod, char to_rod, char mid_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		return;
	}
	tower_Of_hanoi(n-1, from_rod, mid_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c ", n, from_rod, to_rod);
	tower_Of_hanoi(n-1, mid_rod, to_rod, from_rod);
}
int main()
{
	int n;
	printf("ENTER THE NO OF DISKS\n");
	scanf("%d",&n);
	tower_Of_hanoi(n, 'f', 't', 'm'); 
	printf("\n");
	return 0;
}

