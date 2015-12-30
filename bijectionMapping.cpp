#include<iostream>
#include<unordered_map>


class Solution {
private:
    vector<string> tokenize(string str, char delimiter)
    {
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
public:
    bool wordPattern(string pattern, string str) {
        if(pattern.length()==0 && str.length() > 0)
            return false;
            
        vector<string> tokens = tokenize(str, ' ');
        if(pattern.length()!= tokens.size())
            return false;
            
        
        unordered_map<char, string> mapping;
        unordered_map<string, char> inverse_mapping;
        unordered_map<char, string>::iterator iter;
        unordered_map<string, char>::iterator inverse_iter;
        
        for(int i=0;i<pattern.length();i++)
        {
            iter = mapping.find(pattern[i]);
            if(iter==mapping.end())
            {
                inverse_iter = inverse_mapping.find(tokens[i]);
                if(inverse_iter!= inverse_mapping.end())
                    // Not a bijection
                    return false;
                    
                // Insert
                mapping.insert(pair<char, string> (pattern[i], tokens[i]));
                inverse_mapping.insert(pair<string, char> (tokens[i], pattern[i]));
                
            }
            else
            {
                if(tokens[i].compare(iter->second) != 0)
                    return false;
            }
        }
            
        return true;
        
    }
};