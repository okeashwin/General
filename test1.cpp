#include<iostream>
using namespace std;

class A {
	int *a=new int;
	int b;
public:
	int getA() {
		return *a;
	}

	int getB() {
		return b;
	}
};

struct B {
	int *a=new int;
	int b;
};

int main() {
	A a;
	B b;
	cout << a.getA() << endl;
	cout << *(b.a) << endl;

	cout << a.getB() << endl;
	cout << b.b << endl;
}