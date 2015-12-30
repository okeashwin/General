#include<stdio.h>

int noOfOnes(int num)
{
	int sizeInt = sizeof(int)*8;
	int result = 0;
	int i = 1;
	for(;i< sizeInt;i++)
	{
		if(num & 1)
			result++;
		num = num >> 1;
	}

	return result;
}

int main()
{
	printf("%d\n", noOfOnes(7));
	printf("%d\n", noOfOnes(-10));
	printf("%d\n", noOfOnes(10));
	printf("%d\n", noOfOnes(4));
}