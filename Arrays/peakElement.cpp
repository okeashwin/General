
// A peak element is an element that is greater than its neighbors.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
            
        // Check for boundaries
        int size = nums.size();;
        
        if(nums[0] > nums[1])
            return 0;
        if(nums[size - 1] > nums[size - 2])
            return size - 1;
            
        for(int i=1;i<nums.size()-1;i++)
        {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        
        return -1;
    }
};