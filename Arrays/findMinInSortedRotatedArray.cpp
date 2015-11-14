/*
To find the minimum element in a sorted rotated array
*/


class Solution {
private:
    int findMinHelper(vector<int>& nums, int start, int end)
    {
        if(start > end) // No rotation at all
            return nums[0];
            
        if(start==end) // Single element array
            return nums[start];
            
        int middle = (start + end)/2;
        
        if(nums[middle] > nums[middle + 1])  //This is the pivot
            return nums[middle + 1];
        
        if(nums[middle - 1] > nums[middle]) // Pivot is just to the left
            return nums[middle];
            
        if(nums[end] > nums[middle]) // Everything to the right is in order, recur in the left
            return findMinHelper(nums, start, middle - 1);
        
        return findMinHelper(nums, middle + 1, end);
    }
    
public:
    int findMin(vector<int>& nums) {
        return findMinHelper(nums, 0, nums.size()-1);
        
    }
};

/*
Search in sorted rotated array
*/

class Solution {
private:
    int searchHelper(vector<int>& nums, int target, int start, int end)
    {
        if(start > end)
            return -1;
        
        int middle = (start + end)/2;
        if(nums[middle] == target)
            return middle;
        
        if(nums[end] > nums[middle])   
        // middle to high is sorted
            /*
            Idea is now to check if the target lies in this sorted range, if yes, recur the search in the right half, ( it will be a traditional
            binary search in the further steps)
            If the target does not lie in this range, recur to the left. Pivot is somewhere in the left, the left half could contain elements
            greater then nums[middle]

            eg. 9 10 0 1 2 3 4 5 6 7 8 
            */
        {
            // Check if target lies in the sorted range, if yes, direct it to the right subarray
            if(target > nums[middle] && target <= nums[end])
                return searchHelper(nums, target, middle + 1, end);
            else
                return searchHelper(nums, target, start, middle - 1);
        }
        
        else // nums[high] < nums[middle], left side must be sorted
            /*
            Idea is now to check if the target lies in this sorted range, if yes, recur the search in the left half, ( it will be a traditional
            binary search in the further steps)
            If the target does not lie in this range, recur to the right. Pivot is somewhere in the right, the right half could contain elements
            smaller then nums[middle]

            eg. 5 6 7 8 9 10 11 0 1 2 3 4
            */
        {
            if(target < nums[middle] && target >= nums[start])
                return searchHelper(nums, target, start, middle - 1);
            else
                return searchHelper(nums, target, middle + 1, end);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size()-1);
    }
};