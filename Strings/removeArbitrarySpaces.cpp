#include<iostream>
#include<cstdlib>

using namespace std;

void removeArbitrarySpaces(string& input)
{
	char currChar = ' ';
	char prevChar;
	int uniqueIndex = 0;
	for(int i=0;i < input.size();i++)
	{
		prevChar = currChar;
		currChar = input[i];
		if(currChar==prevChar && prevChar==' ')
		{}
		else
		{
			input[uniqueIndex] = input[i];
			uniqueIndex++;
		}
	}

	// Resize the string
	// A special case, if the last character of the processed string is a ' ', this is unwanted
	if(input[uniqueIndex - 1] == ' ')
		input.resize(uniqueIndex-1);
	else
		input.resize(uniqueIndex);
}

int main()
{
	string test = "         The sky is         blue       ";
	string correct = "The sky is blue";
	string blanks = "                                  ";
	string noBlanks = "";
	removeArbitrarySpaces(test);
	removeArbitrarySpaces(correct);
	removeArbitrarySpaces(blanks);
	removeArbitrarySpaces(noBlanks);
	cout << test << endl; cout << test.size() << endl;
	cout << correct << endl; cout << correct.size() << endl;
	cout << blanks << endl; cout << blanks.size() << endl;
	cout << noBlanks << endl; cout << noBlanks.size() << endl;
}