#include<iostream>
#include<fstream>
#include<errno.h>
#include<cstring>
#include<vector>

#include "util.cpp"

using namespace std;

bool logging=false;


int main(int argc, char *argv[]) {
	if(argc<3) {
		usage();
		return 0;
	}
	ofstream log_file;
	if(argc==4) {
		//logging is enabled
		cout << "Logging is enabled"<<endl;
		log_file.open(argv[3]);
		if(!log_file.is_open()) {
			cout << "Log file couldn't be opened : "<<strerror(errno)<<endl;
		}
		else {
			logging = true;
		}
	}

	ifstream inp_file;

	inp_file.open(argv[1]);
	if(!inp_file.is_open()) {
		if(logging) log_file << "Unable to open the circuit file : "<< strerror(errno) << endl;
		if(logging) log_file << "Exiting"<< endl;
		return 0; 
	}

	// Circuit file is opened
	string line;
	while(getline(inp_file, line)) {
		if(logging) log_file << "Read line "<<line << endl;
		cout << line << endl;
		vector<string> tokens = tokenize(line, ' ');
		printVec(tokens);

	}
}