#include<stdio.h>

int main() {
	char *temp="Linux";
	printf("%c\n", *temp++);
	printf("%c\n",*temp);
	return 0;
}