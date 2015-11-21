#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*
Returns a new string : Immutable approach
*/
string compress(string input)
{
	string output;
	char prevChar = input[0];
	char currChar;
	int currCharCount = 0;
	output.append(1, prevChar);
	currCharCount++;
	for(int i=1;i<input.size();i++)
	{
		currChar = input[i];

		if(currChar==prevChar)
		{
			currCharCount++;
		}
		else
		{
			// Append the frequency of the curr running character
			output.append(1, char (currCharCount + 48));
			currCharCount = 1;
			output.append(1, currChar);
			prevChar = currChar;
		}
	}

	output.append(1, char(currCharCount + 48));
	return output;
}

/*
Mutable form
*/
void compressString(string& input)
{
	
}
int main()
{
	string test("aaabbccc");
	cout << compress(test) << endl;

	string test1("abc");
	cout << compress(test1) << endl;
}