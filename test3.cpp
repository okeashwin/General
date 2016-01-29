#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result="11";
        if(n==1) {
            return result.substr(1);
        }
        if(n==2) {
            return result;
        }
        string prev;
        int curr;
        char currChar;
        for(int i=2;i<n;i++) {
        	prev.clear();
            prev=result;
            result.clear();
            currChar=prev[0];
            curr=1;
            cout<<prev.length()<<endl;
            for(int j=0;j<prev.length()-1;j++) {
                //cout<<j<<endl;
                if(prev[j]==prev[j+1]) {
                    curr++;
                } 
                else {
                    result.append(to_string(curr)+currChar);
                    // cout<<result<<endl;
                    curr=1;
                    currChar=prev[j+1];
                }
            }
            result.append(to_string(curr)+currChar);
        }
        return result;
    }
};

int main() {
	Solution sol;
	cout << sol.countAndSay(4)<<endl;
}