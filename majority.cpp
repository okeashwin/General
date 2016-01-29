#include<iostream>
#include<cmath>

using namespace std;

int majority(int *nums, int size) {
	int maj=nums[0];
	int count=1;
	for(int i=1;i<size;i++) {
		if(nums[i]==maj) {
			count++;
		}
		else {
			count--;
		}
		if(count==0) {
			maj=nums[i];
			count=1;
		}
	}

	count=0;
	for(int i=0;i<size;i++) {
		if(nums[i]==maj) {
			count++;
		}
	}		
	return (count>ceil(size/2))?maj:-1;
	
}

int main() {
	int arr[10]={1,5,2,2,2,3,4,1,1,1};
	cout<< majority(arr, 10) << endl;
}