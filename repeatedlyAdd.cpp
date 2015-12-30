#include <iostream>
#include <cstdlib>

using namespace std;

int repeatedlyAdd(int number)
{
	int sumOfDigits = 0;
	while(number > 0)
	{
		sumOfDigits += number%10;
		number = number /10;
	}
	cout << sumOfDigits << endl;
	if(sumOfDigits/10 > 0)
		return repeatedlyAdd(sumOfDigits);
	else
		return sumOfDigits;
}
int main()
{
	cout << "Result : " << repeatedlyAdd(123456) << endl;

}