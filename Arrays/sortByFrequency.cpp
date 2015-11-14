#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

bool debug = false;

struct count
{
	int data;
	int freq;
};

typedef struct count count;

void insertion_sort(count frequency[], int size)
{
	int i=0;
	int j;
	for(;i<size;i++)
	{
		int temp_freq = frequency[i].freq;
		int temp_data = frequency[i].data;
		j = i-1;
		while(frequency[j].freq < temp_freq && j>=0)
		{
			frequency[j + 1].freq = frequency[j].freq;
			frequency[j + 1].data = frequency[j].data;
			j--;
		}

		frequency[j+1].data = temp_data;
		frequency[j+1].freq = temp_freq;
	}
}

void print (count frequency[], int size)
{
	for(int i=0;i<size;i++)
		cout << "Element at " << i << " : " << frequency[i].data << " , " << " Frequency : " << frequency[i].freq << endl;

}

void sortByFrequency(int arr[], int size)
{
	// Create an ordered map to construct the <element, frequency> pair
	map<int, int> freq;
	map<int, int>::iterator iter;

	for(int i=0;i<size;i++)
	{
		iter = freq.find(arr[i]);
		if(iter!= freq.end())
		{
			// This element exists, increase the count
			iter->second++;
		}
		else
		{
			// Insert this pair
			freq.insert(pair<int, int>(arr[i], 1));
		}
	}

	// Check the map
	if(debug)
	{
		for(iter = freq.begin(); iter!= freq.end();iter++)
			cout << "Key : " << iter->first << " , " << " Value : " << iter->second << endl;
	}

	// Traverse the map and place the contents in a count array
	int countSize = freq.size();
	count frequency[countSize];
	int i=0;
	for(iter = freq.begin(); iter!= freq.end(); iter++)
	{
		frequency[i].data = iter->first;
		frequency[i].freq = iter->second;
		i++;
	}

	if(debug) print(frequency, countSize);
	// Sort frequency by decreasing order of freq
	insertion_sort(frequency, countSize);
	if(debug) print(frequency, countSize);

	// Prepare the final array now
	int k=0;
	for(int i=0;i<countSize;i++)
	{
		for(int j=0;j<frequency[i].freq;j++)
		{
			arr[k] = frequency[i].data;
			k++;
		}
	}
}

void printArray(int arr[], int size)
{
	cout << endl;
	cout << "Array " << endl;
	for(int i=0;i<size;i++)
	{
		cout << arr[i] << " , ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
	int size = sizeof(arr)/ sizeof(arr[0]);
	printArray(arr, size);
	sortByFrequency(arr, size);
	printArray(arr, size);
}