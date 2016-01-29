class Solution {
private:
    bool perfectSquare(int x) {
        float root=sqrt(x);
        return root-(int)root==0;
    }
public:
    int numSquares(int n) {
        int func[n+1];
        for(int i=0;i<=n;i++) {
            func[i]=INT_MAX;
        }
        func[0]=0;
        func[1]=1;
        for(int i=2;i<=n;i++) {
            if(perfectSquare(i)) {
                func[i]=1;
            }
            else {
                for(int j=1;j*j<=i;j++) {
                    if(1+func[i-j*j] < func[i]) {
                        func[i]=1+func[i-j*j];
                    }
                }
            }
        }
        
        return func[n];
    }
};