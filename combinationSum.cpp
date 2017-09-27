/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times. 


For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is: 

[
  [7],
  [2, 2, 3]
]

*/


class Solution {
private:
    // A greedy recursive routine that goes on constructing potential candidate sets and checks whether
    // it is a solution set or not
    void helper(vector<vector<int>>& result, vector<int>& tempSol, vector<int>& c, int tar, int& rsum, int start, int end) {
        if(rsum>=tar) {
            // rsum == tar; means we have found a solution set
            if(rsum==tar) result.push_back(tempSol);
            return;
        }
        
        for(int i=start;i<=end;i++) {
            if(c[i]>tar) {
                break;
            }
            tempSol.push_back(c[i]);
            rsum+=c[i];
            helper(result, tempSol, c, tar, rsum, i, end);
            // IMP: backtrack, pop the element from the vector, update the running sum
            tempSol.pop_back();
            rsum-=c[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int tar) {
        int len=c.size();
        if(!len) {
            return vector<vector<int>>();
        }
 
        vector<int> tempSol;
        vector<vector<int>> result;
        sort(c.begin(), c.end());
        int sum=0;
        helper(result, tempSol, c, tar, sum, 0, len-1);
        return result;
    }
};