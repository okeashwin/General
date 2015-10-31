

/*

How this works,
A map that stores ( total - nums[i], curr index) into the map
If in some iteration, we find this key in the map, we are sure we have got a pair
Some processing with the indices and we are done

Complexity : 
Outer loop : O(n) iterations
Inner loop : a map find() operation : O(lg n)
http://stackoverflow.com/questions/9961742/time-complexity-of-find-in-stdmap

So, w(n) and o(n lgn)

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> candidates;
        vector<int>::iterator vecIter = nums.begin();
        map<int,int>::iterator search;
        int i=0;
        int index = 0;
        int second_index=0;
        bool found = false;
        for(;i < nums.size() ; i++)
        {
            search = candidates.find(nums[i]);
            if(search != candidates.end())
            {
                index = search->second + 1;
                second_index = i + 1;
                found = true;
                break;
            }
            
            else
            // Insert in the map it's counterpart
            {
                candidates.insert(pair<int,int>(target - nums[i], i));
            }
        }
        
        if(found)
        {
            if(index > second_index)
            {
                result.push_back(second_index);
                result.push_back(index);
            }
            else
            {
                result.push_back(index);
                result.push_back(second_index);
            }
        }
        
        return result;
    }
};