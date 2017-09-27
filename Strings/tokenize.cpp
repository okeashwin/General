 #include<iostream>
 using namespace std;   

class Solution {
    static string getNextToken(string s) {
        static int curr=0, start=0;
        int len=s.length();
        if(len==0 || curr>=len) {
            return "";
        }
        string result;
        for(;curr<len;curr++) {
            if(s[curr]==' ') {
                result=s.substr(start, curr-start);
                start=curr+1;
                break;
            }
        }
        if(start!=len) {
            result=s.substr(start);
        }
        return result;
    }
}