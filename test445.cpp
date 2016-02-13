#include<iostream>
using namespace std;

class Student {
private:
	char *name;
};

int main() {
	Student *s=new Student();
	Student s1=*s;
	Student s2;
	s2=s1;
	delete s;
	return 0;
}
