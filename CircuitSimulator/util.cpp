#include<vector>
#include<string>
#include<climits>
#include<cstdlib>
#include "structures.h"
using namespace std;


void usage(){

}

unit instantiate() {
    unit *new_el = (unit *)malloc(sizeof(struct unit));
    new_el->_operator = NONE;
    new_el->ip_port[0] = INT_MIN;
    new_el->ip_port[1] = INT_MIN;
    new_el->op_port = INT_MIN;
    return *new_el;
}

vector<string> tokenize(string str, char delimiter) {
    if(str.length()==0)
        return vector<string>();
        
    vector<string> result;
    string currToken;
    int startIndex = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==delimiter)
        {
            currToken.insert(0, str, startIndex, i-startIndex);
            result.push_back(currToken);
            startIndex = i+1;
            currToken.clear();
        }
    }
    
    // Take care of the last token
    if(startIndex <= str.length()-1)
    {
        currToken.insert(0, str, startIndex, str.length()-startIndex);
        result.push_back(currToken);
    }
    
    return result;
}

void printVec(vector<string> tok) {
    cout << "vec contents :"<< endl;
    for(int i=0;i<tok.size();i++) {
        cout << tok[i]<<",";
    }
    cout << endl;
}