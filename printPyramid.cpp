#include<iostream>
using namespace std;

void printPyramid(int height) {
	int start=height-1, end=height-1;
	for(int iter=0;iter<height;iter++) {
		for(int j=0;j<start;j++) {
				cout<<" ";
		}

		for(int i=start;i<=end;i+=2) {
			cout<<"# ";
		}
		start--;
		end++;
		cout<<endl;
	}
}

int main() {
	cout<<"---------"<<endl;
	printPyramid(31);
}