#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int firstRepeatingElement(vector<int> nums)
{
	unordered_map<int, int> elements;
	unordered_map<int, int>::iterator mapIter;
	int minIndex = INT_MAX;
	for(int i=0;i<nums.size();i++)
	{
		mapIter = elements.find(nums[i]);
		if(mapIter != elements.end())
		{
			// Check for minIndex
			if(mapIter->second < minIndex)
				minIndex = mapIter->second;
		}
		else
			elements.insert(pair<int, int> (nums[i], i));
	}

	return nums[minIndex];
}

int main()
{
	int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
	vector<int> nums ( arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << firstRepeatingElement(nums) << endl;

}