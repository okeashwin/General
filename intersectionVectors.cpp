#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> getIntersection(vector<vector<int> > inputs)
{
	if(inputs.size()==0)
		return set<int>();

	// initialize the intersection set with vec0
	set<int> intersection;
	vector<int>::iterator iter = inputs[0].begin();
	set<int>::iterator setIter;

	for(;iter!= inputs[0].end();iter++)
		intersection.insert(*iter);

	// Inspect all the subsequent vectors
	int k=1;

	for(k=1;k<inputs.size();k++)
	{
		for(setIter = intersection.begin(); setIter != intersection.end(); setIter++)
		{
			for(int j=0;j < inputs[k].size();j++)
			{
				iter = find(inputs[k].begin(), inputs[k].end(), *setIter);
				if(iter==inputs[k].end())
					// Erase this element from the intersection set
					intersection.erase(*setIter);
			}
		}
	}

	return intersection;
}

void printSet(set<int> intersection)
{
	if(intersection.size()==0)
	{
		cout << "Empty Set" << endl;
		return;
	}

	set<int>::iterator iter = intersection.begin();
	for(;iter!= intersection.end(); iter++)
		cout << *iter << " , ";
	cout << endl;
}

int main()
{
	int arr1[] = {1,2,3,4,5,6,7,8,9};
	int arr2[] = {1,3,5,7,9};
	int arr3[] = {1,3};

	vector< vector<int> > inputs(3);

	inputs[0].insert(inputs[0].end(), arr1, arr1 + sizeof(arr1)/ sizeof(arr1[0]));
	inputs[1].insert(inputs[1].end(), arr2, arr2 + sizeof(arr2)/ sizeof(arr2[0]));
	inputs[2].insert(inputs[2].end(), arr3, arr3 + sizeof(arr3)/ sizeof(arr3[0]));

	set<int> intersection = getIntersection(inputs);
	printSet(intersection);
	return 0;
}