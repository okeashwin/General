class Solution {
public:
    string addBinary(string a, string b) {
        
        string result;
        
        // Let's make the lengths equal at first
        if(a.size() != b.size())
        {
            if(a.size() > b.size())
            // Prepend 0s to B
            {
                while(a.size()!=b.size())
                    b.insert(0, 1, '0');
            }
            
            else
            // b is longer
            // Prepend 0s to A
            {
                while(a.size()!=b.size())
                    a.insert(0, 1, '0');
            }
        }
        
        // Both are of the same length now
        int i = a.size() - 1;
        bool carryForward = false;
        char sumChar;
        while(i >=0 )
        {
            // Setup the sumChar based on any carry propagated from previous step
            if(carryForward)
            {
                sumChar = '1';
            }
            else
            {
                sumChar = '0';
            }
            
            // XOR between the 3 chars
            sumChar = sumChar ^ a[i] ^ b[i];

            // Carry chances
            /*
                sumChar   a[i]    b[i]
                0           0       0       No carry
                0           0       1       Carry (1st if)
                0           1       0       Carry (1st if)
                0           1       1       Carry (1st if)
                1           0       0       No carry
                1           0       1       No Carry
                1           1       0       No Carry
                1           1       1       Carry ( else if)

            */
            if(sumChar=='0' && (a[i]!= '0' || b[i]!= '0'))
            {
                carryForward = true;
            }
            // 3. Previous carry and both the chars are 1
            else if(sumChar=='1' && a[i]=='1' && b[i]=='1')
            {
                carryForward = true;
            }
            else
            {
                carryForward = false;
            }
            
            result.insert(0,1,sumChar);
            i--;
        }
        
        if(carryForward)
        {
            result.insert(0,1,'1');
        }
        return result;
        
    }
};