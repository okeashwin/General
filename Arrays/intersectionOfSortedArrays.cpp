#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public: vector<int> intersect(const vector<int> &A, const vector<int> &B);
};

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int n1=A.size();
    int n2=B.size();
    int i=0, j=0;
    vector<int> result;
    while(i<n1 && j<n2) {
        if(A[i]==B[j]) {
            result.push_back(A[i]);
            i++;j++;
        }
        else if(A[i]<B[j]) {
            i++;
        }
        else j++;
    }
    return result;
}

void printVec(vector<int> res) {
    int i=0, n=res.size();
    for(;i<n;i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int arr[]={1,2,3,3,4,5,6};
    int arr2[]={3,3,5};
    const vector<int> a1 (arr, arr+sizeof(arr)/sizeof(int));
    const vector<int> a2 (arr2, arr2+sizeof(arr2)/sizeof(int));

    Solution sol;
    vector<int> res= sol.intersect(a1,a2);

    printVec(res);
}