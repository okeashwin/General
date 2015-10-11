#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

string insertAt(string temp, char first, int pos);
vector<string> permute(string test)
{
	int len=test.length();
	vector<string> final_result;
	if(len==0)
	{
		final_result.push_back("");
		return final_result;
	}
	else
	{
		char first=test[0];
		string rem=test.substr(1,string::npos);
		vector<string> result;
		//cout << rem << endl;		
		result=permute(rem);
		vector<string>::const_iterator cii;
		for(cii=result.begin();cii!=result.end(); cii++)
		{
			string temp=*cii;
			//Insert the character at every place in *cii
			for(int j=0;j<=temp.length();j++)
			{
				string s=insertAt(temp,first,j);
				final_result.push_back(s);
			}
		}
		return final_result;
		//return vector<string>();
		
	}
}

string insertAt(string temp, char first, int pos)
{
	string result;
	//string test2("ashwin");
	string start=temp.substr(0,pos);
	string end=temp.substr(pos,temp.length()-pos);
	return start+first+end;
	/*int j=0;
	int k=0;
	int len=temp.length();
	cout << "first "<<first<<" pos " <<pos<<endl;
	while(j<=len)
	{
		if(j==pos)
			result[j]=first;
		else
		{
			result[j]=temp[k];
			k++;
		}
		j++;
		//cout << "Here"<<endl;
	}
	result[j]='\0';
	cout << "result "<<result<<endl;
	return result;*/
}


int main()
{
	string test;
	vector<string> res;
	cout << "Enter the string"<<endl;
	cin >> test;
	//cout << test << endl; 
	int len=test.length();
	res=permute(test);
	vector<string>::const_iterator iter;
	for(iter=res.begin();iter!=res.end();iter++)
		cout << *iter << endl;
	return 0;
}
