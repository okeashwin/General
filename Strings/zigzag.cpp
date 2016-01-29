#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) {
            return s;
        }
        
        int col,alternate;
        if(numRows==2) {
            col=s.length()/(numRows)+1;
            alternate=numRows;
        }
        else {
            col=s.length()/(numRows-1) +1;
            alternate=numRows-2;
        }
        
        char **matrix=(char **)malloc(sizeof(char *)*numRows);
        for(int i=0;i<numRows;i++) {
            matrix[i]=(char *)malloc(sizeof(char)*col);
        }
        for(int i=0;i<numRows;i++) {
            for(int j=0;j<col;j++) {
                matrix[i][j]=' ';
            }
        }
        
        int start,end,j,el,curr;
        int stringIndex=0;
        bool sub=false;
        bool stringProcessed=false;
        for(int i=0;i<col;i++) {
            if(i%2==0) {
                start=0;
                end=numRows-1;
                sub=false;
            }
            else {
                start=(numRows==2)?0:numRows-2;
                end=(numRows==2)?numRows-1:1;
                sub=(numRows==2)?false:true;
            }
            el=abs(end-start);
            curr=0;
            j=start;
            cout<<start<<'\t'<<end<<endl;
            while(curr<=el) {
                matrix[j][i]=s[stringIndex];
                stringIndex++;
                curr++;
                if(sub) {
                    j--;
                }
                else {
                    j++;
                }
                if(stringIndex==s.length()) {
                    stringProcessed=true;
                    break;
                }
            }
            if(stringProcessed) {
                break;
            }
        }

        for(int i=0;i<numRows;i++) {
            for(int j=0;j<col;j++) {
                cout << matrix[i][j]<<'\t';
            }
            cout<<endl;
        }
        cout<<endl;
        string output(s);
        stringIndex=0;
        for(int i=0;i<numRows;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]==' ') {
                    continue;
                }
                output[stringIndex]=matrix[i][j];
                stringIndex++;
            }
        }
        return output;
    }
};

int main() {
    string s="ABC";
    Solution sol;
    cout << sol.convert(s, 2)<<endl;
}