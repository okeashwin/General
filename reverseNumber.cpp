#include <iostream>
#include <cstdlib>

using namespace std;

int reverseNum(int num)
{
	bool negative = false;
	if(num < 0)
	{
		negative = true;
		num = -1*num;
	}
	int result=0;
	int digit = 0;
	while(num > 0)
	{
		digit = num%10;
		result = 10*result + digit;
		num = num/10;
	}

	if(negative)
		return -1*result;

	return result;
}

int main()
{
	cout << reverseNum(12345) << endl;
	cout << reverseNum(4456) << endl;
	cout << reverseNum(-4456) << endl;
}