#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

bool duplicateWithinK(vector<int> nums, int k)
{
	bool debug = false;
	queue<int> insertionOrder;
	unordered_set<int> buffer;

	unordered_set<int>::iterator setIter;
	int dequeued = 0;

	for(int i=0;i<nums.size();i++)
	{

		insertionOrder.push(nums[i]);
		setIter = buffer.find(nums[i]);
		if(debug)
			cout << "Inserted " << nums[i] << " into the queue" << endl;
		if(setIter!= buffer.end())
			return true;
		else
			buffer.insert(nums[i]);
		if(insertionOrder.size() <= k)
		{
			// No need to pop out anything
		}

		else
			// Pop from the front of the vector and remove the element from the set as well
		{
			dequeued = insertionOrder.front();
			insertionOrder.pop();
			buffer.erase(dequeued);
			if(debug)
				cout << " Deleted " << dequeued << " from both the queue as well as the set " << endl;
		}
	}

	return false;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 1, 2, 3, 4};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));

	int arr2[] = {1, 2, 3, 1, 4, 5};
	vector<int> nums2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));

	int arr3[] = {1, 2, 3, 4, 5};
	vector<int> nums3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));

	int arr4[] = {1, 2, 3, 4, 4};
	vector<int> nums4(arr4, arr4 + sizeof(arr4)/sizeof(arr4[0]));

	cout << duplicateWithinK(nums,3) << endl;
	cout << duplicateWithinK(nums2,3) << endl;
	cout << duplicateWithinK(nums3,3) << endl;
	cout << duplicateWithinK(nums4,3) << endl;

}