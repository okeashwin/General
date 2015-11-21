#include<iostream>
#include<set>
#include<vector>

using namespace std;

void removeDups(vector<int>& nums)
{
	set<int> nodes;
	set<int>::iterator iter;
	int unique = 0;
	for(int i=0;i<nums.size();i++)
	{
		iter = nodes.find(nums[i]);
		if(iter != nodes.end())
		{
			// Is a duplicate. Do nothing. Let i increment
		}
		else
		{
			nodes.insert(nums[i]);
			nums[unique] = nums[i];
			unique++;
		}
	}

	nums.resize(unique);
}
void printVec(vector<int> nums)
{
	for(int i=0;i<nums.size();i++)
		cout << nums[i] << " ";
	cout << endl;
}


int main()
{
	int arr[] = {9,8,7,6,5,4,3,4,5,6,7,8,9};
	vector<int> nums ( arr, arr + sizeof(arr)/sizeof(arr[0]));
	printVec(nums);
	removeDups(nums);
	printVec(nums);

}