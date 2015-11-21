#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Binary search for strings

int binarySearchHelper(vector<string> input, int start, int end, string target);

int binarySearch(vector<string> input, string target)
{
	return binarySearchHelper(input, 0, input.size() - 1, target);
}

int binarySearchHelper(vector<string> input, int start, int end, string target)
{
	if(start > end)
		return -1;	// Not found

	int middle = start + ( end - start )/2;
	if(input[middle].compare(target) == 0)
		return middle;
	else if(input[middle].compare(target) < 0)	// middle is alphabetically smaller, recur to right
		return binarySearchHelper(input, middle + 1, end, target);
	else // middle > target
		return binarySearchHelper(input, start, middle - 1, target);
}

// Binary search for strings where empty strings are present
int modifiedBinarySearch(vector<string> input, int start, int end, string target)
{
	bool debug = false;
	if(start > end)
		return -1;
	int middle = start + ( end - start )/2;
	
	int lNonEmpty = middle;
	int rNonEmpty = middle;

	// shift left until 1st non-empty string is found
	while(input[lNonEmpty]=="" && lNonEmpty > start)
		lNonEmpty--;

	// shift right until 1st non-empty string is found
	while(input[rNonEmpty]=="" && rNonEmpty < end)
		rNonEmpty++;
	if(debug)
	{
		cout << "======================= New call ==============" << endl;
		cout << start << '\t' << end << endl;
		cout << "str[middle] " << input[middle] << '\t' << "lNonEmpty " << lNonEmpty << "\t" << "rNonEmpty " << rNonEmpty << endl;
	}

	if(input[lNonEmpty].compare(target) == 0)
		return lNonEmpty;
	else if(input[rNonEmpty].compare(target) == 0)
		return rNonEmpty;
	else if(input[rNonEmpty].compare(target) > 0) // recur in left
	{
		if(lNonEmpty==middle)
			return modifiedBinarySearch(input, start, lNonEmpty - 1, target);
		else
			return modifiedBinarySearch(input, start, lNonEmpty, target);
	}

	else // target is greater than lNonEmpty, recur in right
	{
		if(rNonEmpty==middle)
			return modifiedBinarySearch(input, rNonEmpty + 1, end, target);
		else
			return modifiedBinarySearch(input, rNonEmpty, end, target);
	}
}

void printInput(vector<string> input)
{
	for(int i=0;i<input.size();i++)
		cout << "\"" << input[i] << "\", ";
	cout << endl;
}

int main()
{
	const char *arr[] = {"apple", "orange", "banana", "pineapple", "kiwi", "mango", "peach"};
	vector<string> fruits ( arr, arr + 7);
	sort(fruits.begin(), fruits.end());

	cout << binarySearch(fruits, "peach") << endl;
	cout << binarySearch(fruits, "peak") << endl;
	cout << binarySearch(fruits, "apple") << endl;

	cout << "==================Modified Binary Search ================" << endl;

	printInput(fruits);
	fruits.insert(fruits.begin() + 2, "");
	fruits.insert(fruits.begin(), "");
	fruits.insert(fruits.begin() + 3, "");
	fruits.insert(fruits.begin() + 3, "");
	fruits.insert(fruits.begin() + 3, "");
	fruits.insert(fruits.begin() + 3, "");

	printInput(fruits);
	cout << modifiedBinarySearch(fruits, 0, fruits.size() - 1, "peach") << endl;
	cout << modifiedBinarySearch(fruits, 0, fruits.size() - 1, "peak") << endl;
	cout << modifiedBinarySearch(fruits, 0, fruits.size() - 1, "apple") << endl;

	cout << "==========Regular Binary Search ===============" << endl;

	cout << binarySearch(fruits, "peach") << endl;
	cout << binarySearch(fruits, "peak") << endl;
	cout << binarySearch(fruits, "apple") << endl;

	// Another test sample
	const char *test[] = {"apple", "", "", "ball", "", "", "", "child", "dog", ""};
	vector<string> testVec(test, test + 9);
	cout << modifiedBinarySearch(testVec, 0, testVec.size() - 1, "ball") << endl;

	cout << " ===A short puzzle===="<< endl;
	int i=0; i++ || ++i || i--; cout << i<< endl; 

}