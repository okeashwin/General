#include<iostream>
#include<vector>

using namespace std;

bool isHappy(int n) {
    vector<int> digits;
    int temp;
    int tempSum = n;
    vector<int>::iterator iter;
    while(1)
    {
        digits.clear();
        temp = tempSum;
        while(temp>0)
        {
            digits.push_back(temp%10);
            cout << "Pushed " << temp%10 << endl;
            temp = temp/10;
        }
        
        iter = digits.begin();
        tempSum = 0;
        for(;iter!= digits.end(); iter++)
        {
            cout << *iter << endl;
            tempSum = tempSum + (*iter)*(*iter);
        }
        if(tempSum==1)
            return true;
            
    }
    
}
int main()
{
	cout << isHappy(1) << endl;
}