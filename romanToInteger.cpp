#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

int romanToInteger(string roman)
{
	// Prepare a map for all the literals
	unordered_map<char, int> references;
	references.insert(pair<char, int> ('I',1));
	references.insert(pair<char, int> ('V',5));
	references.insert(pair<char, int> ('X',10));
	references.insert(pair<char, int> ('L',50));
	references.insert(pair<char, int> ('C',100));
	references.insert(pair<char, int> ('D',500));
	references.insert(pair<char, int> ('M',1000));

	unordered_map<char, int>::iterator iter;
	int currDigit, number, prevDigit;
	prevDigit = INT_MAX;
	number = 0;
	for(int i=0;i< roman.size(); i++)
	{
		iter = references.find(roman[i]);
		if(iter==references.end())
		{
			cout << "Invalid character found " << endl;
			return -1;
		}

		currDigit = iter->second;

		if(prevDigit < currDigit)
			// A case of subtraction
			number = number - prevDigit + currDigit - prevDigit;
		else
			number = number + currDigit;

		prevDigit = currDigit;
	}

	return number;
}

int main()
{
	cout << romanToInteger("XXII") << endl;
	cout << romanToInteger("XCIX") << endl;
}