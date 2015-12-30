#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char *input)
{
	int startIndex = 0;
	int endIndex = strlen(input) - 1;
	while(startIndex<= endIndex)
	{
		char temp = input[startIndex];
		input[startIndex] = input[endIndex];
		input[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}

int main()
{
	char *constant = "qwerty";
	char *input = (char *) malloc(sizeof(char)*(strlen(constant) + 1));
	strcpy(input, constant);
	// scanf("%s\n", input);
	printf("%s\n", input);
	reverse(input);
	printf("%s\n", input);
}