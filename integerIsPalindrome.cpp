#include <iostream>
#include <cmath>
using namespace std;

// Test if an integer is a palindrome
bool isPalindrome(int number)
{
	int digits = 0;
	int temp = number;
	while(temp > 0)
	{
		digits++;
		temp = temp/10;
	}

	int msb = digits - 1;
	int msbValue = 0;
	int lsbValue = 0;
	temp = number;
	while(temp > 0)
	{
		msbValue = temp / pow(10, msb);
		lsbValue = temp%10;
		if(msbValue != lsbValue)
		{
			return false;
		}

		temp = temp - msbValue*pow(10,msb);
		temp = temp/10;
		msb = msb - 2;
	}

	return true;
}

int reverse(int number)
{
	int temp = number;
	int rev = 0;
	int digit = 0;
	while(temp > 0)
	{
		digit = temp%10;
		rev = 10*rev + digit;
		temp = temp/10;
	}

	return rev;
}

int main()
{
	cout << isPalindrome(323) << endl;
	cout << isPalindrome(123) << endl;
	cout << reverse(100) << endl;
	cout << reverse(999) << endl;
	cout << reverse(12345) << endl;
}
