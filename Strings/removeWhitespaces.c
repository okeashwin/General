#include<stdio.h>
#include<string.h>

// Remove whitespaces from a string
char *removeWhitespaces(char *input)
{
	if(input==NULL || strlen(input)==0)
		return input;
	char *iter = input;
	char *unique = input;
	while(*iter!='\0')
	{
		printf("Processing : %c\n", *iter);
		// cout << "Unique is " << *unique << endl;
		if(*iter == ' ')
		{
			iter++;
			// Just want iter to increment
		}
		else
		{
			*unique = *iter;
			unique++;
			iter++;
		}
	}

	*unique = '\0';
	return input;

}

int main()
{
	char *test = "        alskdalsd   ";
	printf("%s\n", removeWhitespaces(test));
}