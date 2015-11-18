#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
    static vector<int> twoSum(vector<int>& nums, int target) {
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
            // if(index > second_index)
            // {
            //     result.push_back(second_index);
            //     result.push_back(index);
            // }
            // else
            // {
            //     result.push_back(index);
            //     result.push_back(second_index);
            // }

            result.push_back(nums[index -1]);
            result.push_back(nums[second_index-1]);
        }
        
        return result;
    }
};

/*
A second twoSum : Sort the array and then have a from left-from right moving mechanism

*/

// Insertion sort
void insertion_sort(vector<int>& nums)
{
    int temp;
    int j=0;
    for(int i=0;i<nums.size();i++)
    {
        j= i-1;
        temp = nums[i];
        while(nums[j] > temp && j>=0)
        {
            nums[j+1] = nums[j];
            j--;
        }

        nums[j+1] = temp;
    }
}

void printVector(vector<int> result)
{
    for(int i=0;i<result.size();i++)
        cout << result[i] << " ";
    cout << endl;
}

void twoSum(vector<int>& nums, int target)
{
    insertion_sort(nums);
    printVector(nums);
    // The array is now sorted
    int lindex = 0;
    int rindex = nums.size() - 1;

    while(lindex < rindex)
    {
        if(nums[lindex] + nums[rindex] == target)
        {
            cout << nums[lindex] << ", " << nums[rindex] << endl;
            lindex++;rindex--;
        }

        else if(nums[lindex] + nums[rindex] > target)
            rindex--;
        else
            lindex++;
    }
}

int main()
{
    int arr[] = {3,4,2,10,8,5,9,90,76,69};
    vector<int> nums ( arr, arr+sizeof(arr)/sizeof(arr[0]));

    // vector<int> result = Solution::twoSum(nums, 79);
    // printVector(result);

    twoSum(nums, 79);

}