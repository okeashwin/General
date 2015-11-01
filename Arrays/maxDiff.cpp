#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        int max_so_far = prices[1] - prices[0];
        int min_so_far = prices[0];
        int i;
        int diff = 0;
        for(i=1;i<prices.size(); i++)
        {
            diff = prices[i] - min_so_far;
            if(diff > max_so_far)
                max_so_far = diff;
            if(prices[i] < min_so_far)
                min_so_far = prices[i];
        }
        
        if(max_so_far > 0)
            return max_so_far;
        else
            return 0;
    }
};