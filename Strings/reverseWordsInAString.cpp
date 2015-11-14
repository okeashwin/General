class Solution {
private :
    vector<string> my_strtok(string s1, char delimiter)
    {
        if(s1.size()==0)
            return vector<string>();
        
        vector<string> tokens;
        string token;
        int startIndex = 0;
        for(int i=0;i < s1.size(); i++)
        {
            if(s1[i]==delimiter)
            {
                token.insert(0, s1, startIndex, i-startIndex);
                if(!token.empty())
                    tokens.push_back(token);
                token.clear();
                startIndex = i+1;
            }
        }
        
        // Last token
        token.insert(0, s1, startIndex, s1.size() - startIndex);
        cout << token << endl;
        if(!token.empty())
            tokens.push_back(token);
        return tokens;
    }
    
    bool isBlank(string s)
    {
        string::iterator iter = s.begin();
        
        while(*iter==' ' && iter!= s.end())
            iter++;
        
        if(iter==s.end())
            return true;
        return false;
    }
public:
    void reverseWords(string &s) {
        
        if(isBlank(s))
        {
            s.clear();
            return;
        }
        vector<string> tokens = my_strtok(s, ' ');
        s.clear();
        
        for(int i= tokens.size() - 1; i>=0; i--)
        {
            s.append(tokens[i]);
            if(i!=0)
                s.append(1, ' ');
        }
    }
};