#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=1;
	int *x=&a;
	void *y=&a;
	char *z=&a;
	printf("a:%p\ta+1:%p\ty:%p\ty+1:%p\n",x,x+1,y,y+1);
}
