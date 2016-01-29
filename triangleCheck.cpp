#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int len1,len2,len3;
	for(int i=0;i<n;i++) {
		cin>>len1>>len2>>len3;
		if(len1+len2<=len3 || len1+len3<=len2 || len2+len3<=len1) {
			cout<<"None of these"<<endl;
		}
		else {
			if(len1==len2 && len2==len3) {
				cout<<"Equilateral"<<endl;
			}
			else if(len1==len2 || len1==len3 || len2==len3) {
				cout<<"Isosceles" << endl;
			}
			else {
				cout<<"None of these" << endl;
			}
		}
	}
}