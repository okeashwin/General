#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void shiftZerosToLeft(vector<int>& input)
{

	int unique = 0;
	int i=0;
	vector<int> result;
	for(;i < input.size(); i++)
	{
		if(input[i]==0)
		{
			int temp = input[unique];
			input[unique] = input[i];
			input[i] = temp;
			unique++;
		}
	}
}

// preserves order
void shiftZerosToLeft2(vector<int>& input)
{
	int index = input.size() - 1;
	int iter = input.size() - 1;
	while(iter >= 0)
	{
		if(input[iter]!=0)
		{
			input[index] = input[iter];
			index--;
		}
		iter--;
	}

	// Copy zeros
	for(int i=0;i<=index;i++)
		input[i] = 0;

}

int main()
{
	int arr[] = {1,3,2,4,5,0,7,8,0,2,3,4,0,44,0};
	vector<int> sample (arr, arr + sizeof(arr)/sizeof(int));
	for(int i=0;i<sample.size();i++)
		cout << sample[i] << ", ";
	cout << endl;

	shiftZerosToLeft(sample);
	for(int i=0;i<sample.size();i++)
		cout << sample[i] << ", ";
	cout << endl;

	cout << "=====================+Preserves Order=================" << endl;
	vector<int> sample2 (arr, arr + sizeof(arr)/sizeof(int));
	for(int i=0;i<sample2.size();i++)
		cout << sample2[i] << ", ";
	cout << endl;

	shiftZerosToLeft2(sample2);
	for(int i=0;i<sample2.size();i++)
		cout << sample2[i] << ", ";
	cout << endl;
}