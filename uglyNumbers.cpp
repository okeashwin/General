#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[13]={1,2,3,4,5,6,8,9,10,12,15,20,25};
        vector<int> init(arr, arr+sizeof(arr)/sizeof(int));
        set<int> ugly(init.begin(), init.end());
        set<int>::iterator iter=ugly.begin();
        if(n<=ugly.size()) {
            int i=1;
            for(;iter!=ugly.end();iter++) {
                if(i==n) {
                    return *iter;
                }
                i++;
            }
        }
        advance(iter,5);
        int counter=ugly.size();
        for(;;iter++) {
            cout << *iter << '\t'<<counter<<endl;
            if(ugly.find((*iter)*2)==ugly.end()) {
                ugly.insert((*iter)*2);
                counter++;
            }
            if(ugly.find((*iter)*3)==ugly.end()) {
                ugly.insert((*iter)*3);
                counter++;
            }
            if(ugly.find((*iter)*5)==ugly.end()) {
                ugly.insert((*iter)*5);
                counter++;
            }

            if(counter>=n) {
                set<int>::iterator it1=ugly.begin();
                int i=1;
                for(;it1!=ugly.end();it1++) {
                    if(i==n) {
                        return *it1;
                    }
                    i++;
                }
            }
        }
        
    }
};

int main()
{
    Solution sol;
    cout << sol.nthUglyNumber(50)<<endl;
}