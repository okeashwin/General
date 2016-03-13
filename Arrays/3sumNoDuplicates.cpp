vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int n=A.size();
    sort(A.begin(), A.end());
    int i=0,l=0,r=0,sum=0;
    vector<vector<int> > result;
    vector<int> sol;
    for(;i<n-2;i++) {
        if(i>0 && A[i]==A[i-1]) continue;
        l=i+1;
        r=n-1;
        while(l<r) {
            sum=A[i]+A[l]+A[r];
            if(sum==0) {
                sol.clear();
                sol.push_back(A[i]);sol.push_back(A[l]);sol.push_back(A[r]);
                result.push_back(sol);
                while(l+1<r && A[r]==A[r-1]) { r--; }
                while(l<r-1 && A[l]==A[l+1]) { l++; }
                l++;r--;
            }
            else if(sum>0) {
                while(l+1<r && A[r]==A[r-1]) { r--; }
                r--;
            }
            else {//sum<0
                while(l<r-1 && A[l]==A[l+1]) { l++; }
                l++;
            }
        }
    }
    return result;
}