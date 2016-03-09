#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

/*
4. Consider the following string S that consists entirely of characters 'A', 'T', 'G' and 'C'. Sort S efficiently.

*/
string countingSort(string& str)
{
    int n=str.length();
    int count[4];
    string result(str);
    memset(count, 0, sizeof(count));
    int i=0;
    for(;i<n; i++) {
        if(str[i]=='A') {
            count[0]++;
        }
        else if(str[i]=='C') {
            count[1]++;
        }
        else if(str[i]=='G') {
            count[2]++;
        }
        else {
            count[3]++;
        }
    }

    for(i=1;i<4;i++) {
        count[i] += count[i-1];
    }

    for(i=0;i<n;i++) {
        if(str[i]=='A') {
            result[count[0]-1]=str[i];
            count[0]--;
        }
        else if(str[i]=='C') {
            result[count[1]-1]=str[i];
            count[1]--;
        }
        else if(str[i]=='G') {
            result[count[2]-1]=str[i];
            count[2]--;
        }
        else {
            result[count[3]-1]=str[i];
            count[3]--;
        }
    }
    return result;
}

int main() {
    string test="GACTTAAGAGTTTAATATGACTTAAACATTAAAAGCTCACACTACCCCGAAATATATAATTTCACGCATACGGTGAGATCGGAAGAGCGTCGTGTAGGGAAAGAGTGTAGATCTCGGTGGTCGCC";
    string test2="ACCCCCCCCCCCCCCCCCCCCCCCCCCCCCA";
    string result=countingSort(test);
    string result2=countingSort(test2);
    cout<<result<<endl;
    cout<<result2<<endl;
}