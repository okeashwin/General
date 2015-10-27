#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;

// Represents two numbers as strings, adds them up and returns the result as a string
string addStrings(string s1, string s2)
{
	bool debug = false;
	if(debug) cout << s1 << endl;
	if(debug) cout << s2 << endl;
	if(s1.size() != s2.size())
	{
		if(s1.size() > s2.size())
		{
			// Prepend to s2
			while(s2.size() != s1.size())
			{
				s2.insert(0,1,'0');
			}

			if(debug) cout << "Updated s2 " << s2 << endl;
		}

		else
		{
			// Prepend to s1
			while(s1.size() != s2.size())
			{
				s1.insert(0,1,'0');
			}

			if(debug) cout << "Updated s1 " << s1 << endl;			
		}
	}

	// Initialize sumString to s1
	string sumString(s1);
	int digitOperand1 = 0;
	int digitOperand2 = 0;
	int digitResult = 0;
	bool carryForward = false;
	for(int i = s1.size()-1; i>=0; i--)
	{
		// char *ref1 = &(s1.at(i));
		// char *ref2 = &(s2.at(i));

		// digitOperand1 = atoi(ref1);
		digitOperand1 = (int) s1.at(i) - 48;
		// digitOperand2 = atoi(ref2);
		digitOperand2 = (int) s2.at(i) - 48;
		digitResult = digitOperand1 + digitOperand2;
		if(carryForward)
		{
			digitResult += 1;
		}

		if(digitResult >= 10)
		{
			carryForward = true;
		}

		else
		{
			carryForward = false;
		} 
		if(debug) cout << s1[i] << '\t' << s2[i] << '\t' << digitOperand1 << '\t' << digitOperand2 << '\t' << digitResult << endl;
		sumString[i] = (char) (48 + digitResult%10);

	}

	if(carryForward)
	{
		sumString.insert(0,1,'1');
	}

	return sumString;
}

// Removes duplicates from a string
void removeDuplicates(string& s1)
{
	bool debug = true;
	set<char> charsSoFar;
	set<char>::iterator it;
	for(int i=0;i<s1.size();)
	{
		it = charsSoFar.find(s1[i]);
		if(it != charsSoFar.end()) //Duplicate
		{
			s1.erase(i,1);
		}
		else
		{
			it = charsSoFar.begin();
			charsSoFar.insert(it, s1[i]);
			i++;
		}
	}
}

// 'atoi'
int my_atoi(string s1)
{
	if(s1.empty())
	{
		return -1;
	}

	int retValue = 0;
	int digit = 0;
	for(int i=0;i<s1.size();i++)
	{
		if((int) s1.at(i) < 48 || (int) s1.at(i) > 57)
		{
			cout << "Invalid Input detected" << endl;
			return -1;
		}
		digit = (int) s1.at(i) - 48;
		retValue = 10*retValue + digit;
	}

	return retValue;
}

// palindrome
bool isPalindrome(string s1)
{
	if(s1.empty() || s1.size() == 1)
	{
		return true;
	}

	string::iterator it = s1.begin();
	string::iterator rit = s1.end() - 1;

	for(;it != rit;)
	{
		if(*it != *rit)
		{
			return false;
		}

		it++;
		rit--;
	}

	return true;
}

// uppercase to lowercase
string toLower(string s1)
{
	string retValue(s1);
	string::iterator iter = s1.begin();
	string::iterator result_iter = retValue.begin();
	for(;iter != s1.end();iter++, result_iter++)
	{
		if((int) *iter >=65 && (int) *iter <= 90)
		{
			*result_iter = (char) (*iter) + 32;
		}
	}

	return retValue;
}

// lowercase to uppercase
string toUpper(string s1)
{
	string retValue(s1);
	string::iterator iter = s1.begin();
	string::iterator result_iter = retValue.begin();
	for(;iter != s1.end();iter++, result_iter++)
	{
		if((int) *iter >=97 && (int) *iter <= 122)
		{
			*result_iter = (char) (*iter) - 32;
		}
	}

	return retValue;
}

int main()
{
	// string s1, s2;
	// cin >> s1 >> s2;
	// string s3 = addStrings(s1,s2);
	// cout << s3 << endl;
	// string testRemoveDups;
	// cin >> testRemoveDups; removeDuplicates(testRemoveDups); cout << testRemoveDups << endl;

	// string testAtoi;
	// cin >> testAtoi; cout << my_atoi(testAtoi) << endl;

	// string testPalindrome;
	// cin >> testPalindrome;
	// isPalindrome(testPalindrome) ? cout << testPalindrome << " is a palindrome" << endl : cout << testPalindrome << " is not a palindrome" << endl;

	// string testToLower;
	// cin >> testToLower;
	// cout << "toLower() : " << toLower(testToLower) << endl;

	 string testToUpper;
	 cin >> testToUpper;
	 cout << "toUpper() : " << toUpper(testToUpper) << endl;

	return 0;
}
