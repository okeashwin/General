#include<vector>
#include<string>
#include<climits>
#include<cstdlib>
#include<unordered_set>

#include "structures.h"
using namespace std;


void usage() {

}

unit instantiate_unit() {
    unit *new_el = new unit();
    new_el->_operator="";
    new_el->ip_port[0] = INT_MIN;
    new_el->ip_port[1] = INT_MIN;
    new_el->op_port = INT_MIN;
    return *new_el;
}

vector<string> tokenize(string str, char delimiter) {
    if(str.length()==0)
        return vector<string>();
        
    vector<string> result;
    string currToken;
    int startIndex = 0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==delimiter)
        {
            currToken.insert(0, str, startIndex, i-startIndex);
            result.push_back(currToken);
            startIndex = i+1;
            currToken.clear();
        }
    }
    
    // Take care of the last token
    if(startIndex <= str.length()-1)
    {
        currToken.insert(0, str, startIndex, str.length()-startIndex);
        result.push_back(currToken);
    }
    return result;
}

void print_vec(vector<string> tok) {
    cout << "vec contents : ";
    for(int i=0;i<tok.size();i++) {
        cout << tok[i]<<'\t';
    }
    cout << endl;
}

void print_unit_data(unit& obj, ostream& out_desc) {
    out_desc << "Operator : "<< obj._operator << endl;
    out_desc << "Input Ports : ";
    for(int i=0;i<2;i++) {
        if(obj.ip_port[i]!=INT_MIN) {
            out_desc << obj.ip_port[i]<<"  ";
        }
    }
    out_desc << endl;
    out_desc << "Output port : "<< obj.op_port << endl;
}

void fill_sets(vector<string> tokens) {
    unordered_set<int> *curr_set;
    if(tokens[0].compare("INPUT")==0) {
        curr_set = &input_ports;
    }
    else {
        curr_set = &output_ports;
    }

    for(int i=1;i<tokens.size();i++) {
        curr_set->insert(atoi(tokens[i].c_str()));
    }
}

void print_io_ports(ostream& file_desc) {
    unordered_set<int>::iterator iter = input_ports.begin();
    file_desc << "----- Input ports -----" << endl;
    for(;iter!=input_ports.end();iter++) {
        file_desc << *iter << " ";
    }
    file_desc << endl;

    iter = output_ports.begin();
    file_desc << "----- Output ports -----" << endl;
    for(;iter!=output_ports.end();iter++) {
        file_desc << *iter << " ";
    }
    file_desc << endl;
}