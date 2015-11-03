#include <iostream>
#include <vector>

using namespace std;

/*
METHOD 1 : Sort the larger array. Do a Binary Search for all the candidate sub array elements
*/

void sort(vector<int>& array)
{
	int temp;
	int j;
	for(int i=0;i<array.size();i++)
	{
		j = i-1;
		temp = array[i];
		while(j>=0 && array[j] > temp)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}

bool binarySearchHelper(vector<int> array, int start, int end, int searchValue)
{
	if(start > end)
		return false;
	int middle = (start + end)/2;
	if(searchValue == array[middle])
		return true;
	else if(searchValue < array[middle])
		return binarySearchHelper(array, start, middle - 1, searchValue);
	else
		return binarySearchHelper(array, middle + 1, end, searchValue);

}

bool isElementPresent(vector<int> array, int target)
{
	return binarySearchHelper(array, 0, array.size(), target);
}

bool isSubsetOf(vector<int> array, vector<int> subarray)
{
	// Sort the larger array
	sort(array);
	// Search for all the subarray elements
	bool present = false;
	for(int i=0; i< subarray.size(); i++)
	{
		present = isElementPresent(array, subarray[i]);
		if(!present)
			return false;
	}

	return true;
}

/*
METHOD 2 : Insert elements in a set. Check if each element of the subset exists in the set
*/

bool isSubsetOf2(vector<int> array, vector<int> subarray)
{
	set<int> elements;
	return true;
}

int main()
{
	int arr1[] = {11, 1, 13, 21, 3, 7};
	int arr2[] = {11, 3, 7, 1};

	// Make vectors
	vector<int> array(arr1, arr1 + sizeof(arr1)/sizeof(int));
	vector<int> subsetCandidate(arr2, arr2 + sizeof(arr2)/sizeof(int));

	string result = isSubsetOf(array, subsetCandidate)?"Is a Subset": "Not a Subset";

	cout <<  result << endl;
}