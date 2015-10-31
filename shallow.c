#include<stdio.h>
#include<malloc.h>

int main()
{
	int *base = (int *)malloc(sizeof(int));
	*base = 10;
	int *shallow = base;
	int *deep = (int *)malloc(sizeof(int));
	*deep = *base;
	// 10 10 10
	printf("base : %d\tshallow : %d\tdeep: %d\n", *base, *shallow, *deep);

	*base = 20;
	// 20 20 10
	printf("base : %d\tshallow : %d\tdeep: %d\n", *base, *shallow, *deep);
}
