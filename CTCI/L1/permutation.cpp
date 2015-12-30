#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

void sort(string& input);
bool isPermutation(string input1, string input2);

void sort(string& input)
{
	for(int i=0;i < input.length(); i++)
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

bool isPermutation(string input1, string input2)
{
	if(input1.length() != input2.length())
		return false;
	sort(input1);
	sort(input2);
	cout << "Sorted 1 " << input1 << endl;
	cout << "Sorted 2 " << input2 << endl;
	return input1.compare(input2)==0;
}

int main()
{
	string input1 = "qwerty";
	string input2 = "ytrewq";

	cout << isPermutation(input1, input2) << endl;

	string input3 = "qwerty";
	string input4 = "trewq";

	cout << isPermutation(input3, input4) << endl;
}

