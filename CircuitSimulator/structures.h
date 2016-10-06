#include<string>
#include<unordered_set>
#include<vector>

using namespace std;

typedef struct unit {
	string _operator;
	// i/o ports
	int ip_port[2];
	int op_port;
} unit;

vector<unit> trace;
unordered_set<int> input_ports;
unordered_set<int> output_ports;
vector<int> results;