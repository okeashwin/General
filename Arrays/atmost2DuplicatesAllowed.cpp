/*
What if duplicates are allowed at most twice?

IDEA : Maintain a map of frequency: ignore the element if it is already encountered atleast twice before i.e if freq(element) >= 2
Returns the new size of the vector
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int>::iterator iter;
        int i;
        int unique = 0;
        for(i=0;i<nums.size();i++)
        {
            iter = freq.find(nums[i]);
            if(iter==freq.end())
            {
                // Element not present, insert into the map
                freq.insert(pair<int, int>(nums[i], 1));
                nums[unique] = nums[i];
                unique++;
            }
            else
            {
                if(iter->second < 2)
                {
                    iter->second++;
                    nums[unique] = nums[i];
                    unique++;
                }
                else
                // Needs to be removed
                {
                    // Only i needs to be incremented
                }
            }
        }
        return unique;
        
    }
};