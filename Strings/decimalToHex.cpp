#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

string decimaltoHex(int number)
{
	bool isNeg = false;
	if(number < 0)
	{
		isNeg = true;
		number = (-1)*number;
	}
	// Prepare a lookup map
	unordered_map<int, char> conversionMap;
	conversionMap.insert(pair<int, char>(10, 'A'));
	conversionMap.insert(pair<int, char>(11, 'B'));
	conversionMap.insert(pair<int, char>(12, 'C'));
	conversionMap.insert(pair<int, char>(13, 'D'));
	conversionMap.insert(pair<int, char>(14, 'E'));
	conversionMap.insert(pair<int, char>(15, 'F'));

	stack<char> aux;
	string result;
	int digit;
	while(number > 0)
	{
		digit = number%16;
		if(digit > 9)
			aux.push((conversionMap.find(digit))->second);
			// result.append(1, (conversionMap.find(digit))->second);
		else
			aux.push(char(digit + 48));
			// result.append(1, char(digit + 48));
		number = number/16;
	}

	while(!aux.empty())
	{
		result.append(1, aux.top());
		aux.pop();
	}
	if(isNeg)
		result.insert(0,1,'-');
	return result;
}

int main()
{
	cout << decimaltoHex(10) << endl;
	cout << decimaltoHex(15) << endl;
	cout << decimaltoHex(32) << endl;
	cout << decimaltoHex(256) << endl;
	cout << decimaltoHex(92) << endl;
}