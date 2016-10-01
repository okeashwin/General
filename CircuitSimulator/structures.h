using namespace std;

enum Gate {INV, AND, OR, NAND, BUF, NOR, XOR, NONE};

typedef struct unit {
	Gate _operator;
	// i/o ports
	int ip_port[2];
	int op_port;
} unit;

vector<unit> trace;