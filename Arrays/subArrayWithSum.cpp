/*
Find subarray with given sum
Idea : Maintain a running sum, as soon as the running sum exceeds the target, start removing the trailing elements till the 
running sum is less than the target
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

// Returns a vector containing the two indices ( 'from' and 'to')
vector<int> subarrayWithSum(int arr[], int target)
{
	int curr_sum = arr[0];
	int size = sizeof(arr);
	bool ansFound = false;

	// Marks the start index of the subarray
	int startIndex = 0;
	int endIndex = 0;
	int i;
	for(i=1;i<size;i++)
	{
		while(curr_sum > target && startIndex < i-1)	
		{
			curr_sum = curr_sum - arr[startIndex];
			startIndex++;
		}

		if(curr_sum==target)
		{
			endIndex = i-1;
			ansFound = true;
			break;
		}

		curr_sum = curr_sum + arr[i];

	}

	vector<int> result;
	if(ansFound)
	{
		// cout << "pushing " << startIndex << " and " << endIndex << " to vector " << endl;
		result.push_back(startIndex);
		result.push_back(endIndex);
	}

	return result;

}

void printVector(vector<int> result)
{
	for(int i = 0; i< result.size();i++)
		cout << result[i] << " , ";
	cout << endl;
}

int main()
{
	int arr[] = {1, 4, 20, 3, 10, 5};
	vector<int> result = subarrayWithSum(arr, 33);
	printVector(result);

	int arr2[]= {1, 4, 0, 0, 3, 10, 5};
	result.clear();
	result = subarrayWithSum(arr2, 7);
	printVector(result);
	return 0;

}