#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        bool prime[n];
        for(int i=0;i<n;i++) {
            prime[i]=true;
        }
        prime[0]=prime[1]=false;
        for(int i=2;i<n;i++) {
            if(prime[i]==false)
                continue;
            for(int j=i*i;j<n;j+=i) {
                prime[j]=false;
            }
        }
        int count=0;
        for(int i=2;i<n;i++) {
            if(prime[i]) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    cout<<sol.countPrimes(499979) << endl;
    return 0;
}