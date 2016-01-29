#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> arr, int start, int end) {
    for(int i=start;i<=end;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int partition(vector<int>& arr, int start, int end) {
    int pivot=arr[end];
    int tracker=start;
    for(int i=start;i<=end;i++) {
        if(arr[i]<pivot) {
            int temp=arr[i];
            arr[i]=arr[tracker];
            arr[tracker]=temp;
            tracker++;
        }
    }
    // tracker is the 1st greater element
    int temp=arr[tracker];
    arr[tracker]=arr[end];
    arr[end]=temp;
    print(arr,0,arr.size()-1);
    return tracker;
}
void quickSortHelper(vector<int>& arr, int start, int end) {
    if(end>start) {
        int pivot=partition(arr, start, end);
        // cout<< "Calling sorts for "<<start<<","<<pivot-1<<" and "<<pivot+1<<","<<end<<endl;
        quickSortHelper(arr,start,pivot-1);
        quickSortHelper(arr,pivot+1,end);;
    }
}
void quickSort(vector<int>& arr) {
   // Complete this function
    int start=0;
    int end=arr.size()-1;
    quickSortHelper(arr, start, end);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,temp;
    vector<int> vec;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>temp;
        vec.push_back(temp);
    }
    
    quickSort(vec);
    return 0;
}