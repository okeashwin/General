#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;
/*
map is ordered - find/search/insert - O(lg n) = Uses Red Black Trees for impl
unordered_map won't have keys sorted in order - find/search/insert - O(1) = ammortized
*/

int main()
{
	map<int, int> freq;
	unordered_map<int, int> freq_unordered;
	map<int,int>::iterator iter;
	unordered_map<int, int>::iterator iter_unordered;
	int arr[] = {12, 11, 10, 5, 6, 2, 30};
	vector<int> vec(arr, arr + sizeof(arr)/sizeof(int));

	for(int i=0;i<vec.size();i++)
	{
		iter = freq.find(vec[i]);
		iter_unordered = freq_unordered.find(vec[i]);
		if(iter != freq.end())
		{
			iter->second++;
			iter_unordered->second++;
		}
		else
		{
			freq.insert(pair<int,int>(vec[i],1));
			freq_unordered.insert(pair<int,int>(vec[i],1));
		}
	}

	iter = freq.begin();
	cout << "======================Ordered Map=====================" << endl;
	for(;iter!= freq.end(); iter++)
	{
		cout << "Key : " << iter->first << ", Value : " << iter->second << endl;
	}

	iter_unordered = freq_unordered.begin();
	cout << "======================Ordered Map=====================" << endl;
	for(;iter_unordered!= freq_unordered.end(); iter_unordered++)
	{
		cout << "Key : " << iter_unordered->first << ", Value : " << iter_unordered->second << endl;
	}
	return 0;
}