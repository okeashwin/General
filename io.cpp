#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std; 

class Solution {
private:
  map<string, vector<string> > t;
public :
  Solution(string filename) {
  string line, temp;
  vector<string> tokenHolder;
  map<string, vector<string> >::iterator iter;
  ifstream myfile (filename.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        temp=line;
        sort(temp.begin(), temp.end());
        iter=t.find(temp); 
        if(iter==t.end()) {
          tokenHolder.clear();
          tokenHolder.push_back(line);
          t.insert(pair<string,vector<string> > (temp, tokenHolder));
        }
        else {
          (iter->second).push_back(line);
        } 
    }
    myfile.close();
  }

  else cout << "Unable to open file"<<endl;
}

int getMapSize() {
  return t.size();
}

void initiateDict(string filename) {}
};

int main() {
  Solution sol("example.txt");
  cout<<sol.getMapSize()<<endl;
}