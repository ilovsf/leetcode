class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0)
            return 0;
        
        int array_size = s.size();
        int *opt = new int[array_size];
        
        //initialize
        opt[array_size - 1] = (s[array_size - 1] == '0' ? 0 : 1); 
        if(s.size() == 1)
            return opt[0];
        
        //initialize the second number
        if(s[array_size - 2] == '1' || (s[array_size - 2] == '2' && s[array_size - 1] <= '6'))
        {
            opt[array_size - 2] = 1 + opt[array_size - 1];
        }
        else if(s[array_size - 2] == '0')
        {
            opt[array_size - 2] = 0;
        }
        else
        {
            opt[array_size - 2] = opt[array_size - 1];
        }
    
        for(int i = array_size - 1; i > 1; -- i)
        {
            if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))
            {
                opt[i - 2] = opt[i - 1] + opt[i];
            }
            else if(s[i - 2] == '0')
            {
                opt[i - 2] = 0;
            }
            else
            {
                opt[i - 2] = opt[i - 1];
            }
        }
        
        return opt[0];
    }
};