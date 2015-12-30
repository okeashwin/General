#include<iostream>
#include<string>
#include<set>

using namespace std;

bool hasUniqueChars(string input);
bool hasUniqueCharsSorting(string input);
void sort(string& input);

bool hasUniqueChars(string input)
{
	set<char> characters;
	set<char>::iterator iter;

	for(int i=0;i<input.length();i++)
	{
		iter = characters.find(input[i]);
		if(iter == characters.end())
			// The element does not exist. Insert it
			characters.insert(input[i]);
		else
			return false;
	}
	return true;
}

// Without auxiliary DS
bool hasUniqueCharsSorting(string input)
{
	sort(input);
	// cout << "Sorted String : " << input << endl; 
	for(int i=1;i<input.length();i++)
	{
		if(input[i]==input[i-1])
			return false;
	}
	return true;
}

void sort(string& input)
{
	for(int i=0;i<input.length();i++)
	{
		char temp = input[i];
		int j = i-1;
		while(input[j] > temp && j >= 0)
		{
			input[j+1] = input[j];
			j--;
		}
		input[j+1] = temp;
	}
}

int main()
{
	string test="ashwin";
	cout << hasUniqueChars(test) << endl;
	cout << hasUniqueCharsSorting(test) << endl;

	string test2="";
	cout << hasUniqueChars(test2) << endl;
	cout << hasUniqueCharsSorting(test2) << endl;

	string test3="ashwina";
	cout << hasUniqueChars(test3) << endl;
	cout << hasUniqueCharsSorting(test3) << endl;
}