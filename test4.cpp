#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string returnPermutation(string input, vector<string> dict) {
	sort(input.begin(), input.end());
	string currToken;

	for(int i=0;i<dict.size();i++) {
		currToken.clear();
		currToken=dict[i];
		sort(currToken.begin(), currToken.end());
		if(currToken==input) {
			return dict[i];
		}
	}

	return "";
}

int main() {
	
}