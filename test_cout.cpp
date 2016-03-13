#include<iostream>

using namespace std;

int main() {
	cout<<sizeof(cout)<<endl;
	cout<<cin<<endl;

	operator<<(cout, "Hi\n");
}