#include <iostream>
#include <vector>

using namespace std;

int binary_search_iterative(vector<int> nums, int target)
{
	int middle;
	int start = 0;
	int end = nums.size() - 1;
	while(start <= end)
	{
		middle = (start + end)/2;

		if(target == nums[middle])
			return middle;
		else if(target < nums[middle])
			end = middle - 1;
		else
			start = middle + 1;
	}

	return -1;
}

int binarySearchRecursiveHelper(vector<int> nums, int start, int end, int target)
{
	if(start > end)
		return -1;
	int middle = (start + end)/2;
	if(target == nums[middle])
		return middle;
	else if(target < nums[middle])
		return binarySearchRecursiveHelper(nums, 0, middle - 1, target);
	else
		return binarySearchRecursiveHelper(nums, middle + 1, end, target);
}

int binary_search_recursive(vector<int> nums, int target)
{
	return binarySearchRecursiveHelper(nums, 0, nums.size() - 1, target);
}

int binarySearchRecursiveHelperFirstInstance(vector<int> nums, int start, int end, int target)
{
	if(start > end)
		return -1;
	int middle = (start + end)/2;
	// A change here to see if 'middle' is the first instance of 'target'
	if((middle == 0 || nums[middle-1] < target) && target == nums[middle])
		return middle;
	else if(target < nums[middle])
		return binarySearchRecursiveHelperFirstInstance(nums, 0, middle - 1, target);
	else
		return binarySearchRecursiveHelperFirstInstance(nums, middle + 1, end, target);
}

int binary_search_first_instance_of(vector<int> nums, int target)
{
	return binarySearchRecursiveHelperFirstInstance(nums, 0, nums.size() - 1, target);
}

int binarySearchRecursiveHelperLastInstance(vector<int> nums, int start, int end, int target)
{
	if(start > end)
		return -1;
	int middle = (start + end)/2;
	// A change here to see if 'middle' is the first instance of 'target'
	if((middle == nums.size() - 1 || nums[middle + 1] > target ) && target == nums[middle])
		return middle;
	else if(target < nums[middle])
		return binarySearchRecursiveHelperLastInstance(nums, 0, middle - 1, target);
	else
		return binarySearchRecursiveHelperLastInstance(nums, middle + 1, end, target);
}

int binary_search_last_instance_of(vector<int> nums, int target)
{
	return binarySearchRecursiveHelperLastInstance(nums, 0, nums.size() - 1, target);
}

/*

Find a Fixed Point in a given array

Given an array of n distinct integers sorted in ascending order, write a function that returns a Fixed Point in the array, if there is any Fixed Point present in array, else returns -1. 
Fixed Point in an array is an index i such that arr[i] is equal to i. Note that integers in array can be negative. 
*/
int fixedPoint(vector<int> nums)
{
	int lindex = 0;
	int rindex = nums.size() - 1;
	int middle;
	// A small tweak to the traditional Binary Search
	while(lindex <= rindex)
	{
		middle = (lindex + rindex)/2;
		if(nums[middle] == middle)
			return middle;
		else if(nums[middle] < middle)
			lindex = middle + 1;
		else // middle < nums[middle]
			rindex = middle - 1;
	}

	return -1;
}


int main()
{
	int arr[] = {1, 1, 2, 3, 4, 4, 4, 4, 6, 6, 7, 8, 9, 10};
	vector<int> nums(arr, arr + sizeof(arr)/ sizeof(int));
	cout << "Binary Search iterative for 4 : Index " << binary_search_iterative(nums,4) << endl;
	cout << "Binary Search recursive for 4 : Index " << binary_search_recursive(nums,4) << endl;
	cout << "First Index for 4 : Index " << binary_search_first_instance_of(nums,4) << endl;
	cout << "Last Index for 4 : Index " << binary_search_last_instance_of(nums,4) << endl;

	int arr2[10] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	vector<int> nums2(arr2, arr2 + sizeof(arr2)/sizeof(int));
	cout << fixedPoint(nums2) << endl;
	return 0;
}