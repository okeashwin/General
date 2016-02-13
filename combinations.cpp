#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    int getCombs(int n, int k) {
        int dp[n+1][k+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                if(j==0 || i==j) {
                    dp[i][j]=1;
                }
                else {
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[n][k];
    }
public:
    vector<vector<int> > combine(int n, int k) {
        if(n==0) {
            return vector<vector<int> >();
        }
        vector<vector<int> > result;
        vector<int> c;
        int combs=getCombs(n,k);

        int ptr[k];
        for(int i=0;i<k;i++) {
            ptr[i]=i;
        }
        int active=k-1;
        for(int i=0;i<combs;i++) {
            for(int j=0;j<k;j++) {
                c.push_back(ptr[j]+1);
            }
            result.push_back(c);
            c.clear();
            ptr[active]++;
            int j=k-1;
            while(ptr[j]==n-k+j+1 && j>=0) {
                // Reached boundary
                ptr[j-1]++;
                ptr[j]=ptr[j-1]+1;
                j--;
            }
            active=INT_MAX;
            for(int j=k-1;j>=0;j--) {
                if(ptr[j]>=n-k+j+1) {
                    continue;
                }
                else {
                    active=j;
                    break;
                }
            }
            active=(active==INT_MAX)?0:active;
            if(active!=k-1) {
                for(int i=active+1;i<k;i++) {
                    ptr[i]=ptr[i-1]+1;
                }
            }
            active=k-1;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > result=sol.combine(5,3);
}