#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	int n,temp;
	cin>>n;
	vector<int> data;
	for(int i=0;i<n;i++) {
		cin>>temp;
		data.push_back(temp);
	}

	map<int, int> mappingForward;
	map<int, int> mappingBackward;
	map<int, int>::iterator iter;

	for(int i=0;i<data.size();i++) {
		iter=mappingForward.find(data[i]);
		if(iter==mappingForward.end()) {
			mappingForward.insert(pair<int, int>(data[i],1));
			mappingBackward.insert(pair<int, int>(data[i],1));
		}
		else {
			iter->second++;
			iter=mappingBackward.find(data[i]);
			iter->second++;
		}
	}

	string s1,s2;
	for(int i=0;i<n;i++) {
		s1.insert(s1.end(),'0');
		s2.insert(s2.end(),'0');
	}
	cout<<s1<<'\t'<<s2<<endl;

	for(int i=0;i<n;i++) {
		iter=mappingForward.find(data[i]);
		if(iter->second>1) {
			s1[i]='1';
			iter->second--;
		}
	}
	for(int i=n-1;i>=0;i--) {
		iter=mappingBackward.find(data[i]);
		if(iter->second>1) {
			s2[i]='1';
			iter->second--;
		}
	}

	cout<<s1<<'\t'<<s2<<endl;
}