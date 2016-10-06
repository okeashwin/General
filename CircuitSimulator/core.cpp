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
		print_vec(tokens);
		if(tokens[0].compare("INPUT")==0 || tokens[0].compare("OUTPUT")==0) {
			fill_sets(tokens);
			if(logging) print_io_ports(log_file);
		}
		else {
			// A circuit unit
			unit current_unit = instantiate_unit();
			current_unit._operator.append(tokens[0]);
			if(current_unit._operator.compare("INV")==0 || current_unit._operator.compare("BUF")==0) {
				// We get only one input operand here
				current_unit.ip_port[0] = atoi(tokens[1].c_str());
				current_unit.op_port = atoi(tokens[2].c_str());
			}
			else {
				current_unit.ip_port[0] = atoi(tokens[1].c_str());
				current_unit.ip_port[1] = atoi(tokens[2].c_str());
				current_unit.op_port = atoi(tokens[3].c_str());
			}

			if(logging) log_file << "Following circuit unit recorded :" <<endl;
			if(logging) print_unit_data(current_unit, log_file);
			}

	}
}