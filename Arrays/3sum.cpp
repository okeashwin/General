#include <iostream>
#include <cstdlib>
#define N 10

using namespace std;

int *insertion_sort(int *arr, int size)
{
	int i=1;
	int j=0;
	int temp = 0;
	for(; i < size ; i++)
	{
		j = i-1;
		temp = arr[i];
		while(arr[j] > temp && j>=0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}

	return arr;
}


int main()
{
	srand(time(NULL));

	int *arr = (int *)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
		arr[i] = rand()%N;

	for(int i=0;i<N;i++)
		cout << arr[i] << ", ";

	cout << endl;
	arr = insertion_sort(arr, N);

	for(int i=0;i<N;i++)
		cout << arr[i] << ", ";
	cout << endl;

	// ------------------Start off 3sum here
	int target;
	cout << "Enter the target" << endl;
	cin >> target;

	int lindex = 0;
	int rindex = 0;
	for(int i=0;i<N-2;i++)
	{
		lindex = i+1;
		rindex = N-1;
		while(lindex < rindex)
		{
			if(arr[i] + arr[lindex] + arr[rindex] == target)
			{
				cout << "Triplet found : (" << arr[i] <<","<< arr[lindex] <<"," << arr[rindex] << ")" << endl;
				lindex++;rindex--;
			}

			else if (arr[i] + arr[lindex] + arr[rindex] < target)
			// Need to achieve greater sum
				lindex++;
			else
				rindex--;
		}
	}
}