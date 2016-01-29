#include<iostream>
#include<vector>
using namespace std;


typedef struct node
{
    int value;
    int index;
}node;

class NumArray {
private:
    node *data;
    int size;
    
    void buildTree(int nodeIndex, vector<int> nums,int start, int end)
    {
        if(start>end)
            return;
            
        int middle=start+(end-start)/2;
        data[nodeIndex].value=nums[middle];
        data[nodeIndex].index=middle;
        int lindex=2*nodeIndex+1;
        int rindex=2*nodeIndex+2;
        
        buildTree(lindex,nums,start, middle-1);
        buildTree(rindex,nums,middle+1,end);
    }
    
    int search(int nodeIndex, int index)
    {
        if(nodeIndex<0 || nodeIndex>size-1)
            return -1;
            
        if(index==data[nodeIndex].index)
            return nodeIndex;
        else if(index<data[nodeIndex].index)
            // Recur in the left
            return search(2*nodeIndex+1,index);
        else
            return search(2*nodeIndex+2,index);
    }

    void sumRangeHelper(int nodeIndex, int& sum, int start, int end)
    {
        if(nodeIndex < 0 || nodeIndex >=size)
            return;

        if(start<=data[nodeIndex].index && data[nodeIndex].index<=end)
                sum = sum + data[nodeIndex].value;

        if((start<data[nodeIndex].index && end>=data[nodeIndex].index) || (start>=data[nodeIndex].index && end<data[nodeIndex].index))
        {
            sumRangeHelper(2*nodeIndex+1, sum, start, end);
            sumRangeHelper(2*nodeIndex+2, sum, start, end);
        }
        else if(start<=data[nodeIndex].index && end<=data[nodeIndex].index)
            sumRangeHelper(2*nodeIndex+1, sum, start, end);
        else if(start>=data[nodeIndex].index && end>=data[nodeIndex].index)
            sumRangeHelper(2*nodeIndex+2, sum, start, end);
    }
public:
    NumArray(vector<int> &nums) {
        int n=nums.size();
        if(n==0)
        {
            data==NULL;
            return;
        }
        data = new node[n];
        buildTree(0,nums,0,nums.size()-1);
        size=n;
    }

    void update(int i, int val) {
        int index=search(0,i);
        if(index==-1)
            return;
        data[index].value=val;
    }

    int sumRange(int i, int j) {
        
        int sum=0;
        sumRangeHelper(0,sum,i,j);
        return sum;
    }

    void printTree()
    {
        for(int i=0;i<size;i++)
            cout << data[i].value << '\t';
        cout << endl;
    }
};

void print(vector<int> nums)
{
    for(int i=0;i<nums.size();i++)
        cout << nums[i] << '\t';
    cout << endl;
}
int main()
{
    vector<int> nums;
    for(int i=1;i<=8;i++)
        nums.push_back(i);
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 1) << endl;
    numArray.update(2, 10);
    numArray.printTree();
    cout << numArray.sumRange(1, 2) << endl;
    cout << numArray.sumRange(0,7) << endl;
    // numArray.printTree();
}