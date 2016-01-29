class Solution {
    int *minheap;
    int size=0;
    void buildheap(vector<int> nums, int start, int end) {
        for(int i=start;i<=end;i++){
            minheap[i]=nums[i];
            size++;
        }
        int middle=start+(end-start)/2;
        for(int i=middle;i>=0;i--) {
            heapify(i);
        }
    }
    
    void heapify(int index){
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<size && minheap[left]<minheap[index]) {
            smallest=left;
        }
        if(right<size && minheap[right]<minheap[smallest]) {
            smallest=right;
        }
        if(smallest!=index){
            int temp=minheap[index];
            minheap[index]=minheap[smallest];
            minheap[smallest]=temp;
            heapify(smallest);
        }
    }
    void printheap() {
        for(int i=0;i<size;i++) {
            cout << minheap[i] << '\t';
        }
        cout << endl;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        minheap=new int[k];
        
        buildheap(nums,0,k-1);
        
        for(int i=k;i<n;i++)
        {
            if(nums[i]>minheap[0]) {
                minheap[0]=nums[i];
                heapify(0);
            }
        }       
        return minheap[0];       
    }
};