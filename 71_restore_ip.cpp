class Solution {
public:
    bool isValidIP(string &s){
        int len = s.size();
        
        if(len > 3 || len == 0) return false;
        if(s[0] == '0') return len == 1;
        
        int ip = 0, base = 1;
        len --;
        while(len >= 0)
        {
            ip += base * (s[len --] - '0');
            base *= 10;
        }
        
        if(ip > 0 && ip < 256) return true;
        
        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        
        if(s.size() < 4 || s.size() > 12) return result;
        
        int first, second, third;
        string sub1, sub2, sub3, sub4;
        for(first = 1; first < s.size() && first < 4; ++ first)
        {
            sub1 = s.substr(0, first);
            if(!isValidIP(sub1)) continue;
            for(second = first + 1; second < s.size() && second - first < 4; ++ second)
            {
                sub2 = s.substr(first, second - first);
                if(!isValidIP(sub2)) continue;
                for(third = second + 1; third < s.size() && third - second < 4; ++ third)
                {
                    sub3 = s.substr(second, third - second);
                    if(!isValidIP(sub3)) continue;
                    else
                    {
                        sub4 = s.substr(third);
                        if(isValidIP(sub4))
                        {
                            string res = sub1 + "." + sub2 + "." + sub3 + "." + sub4;
                            result.push_back(res);
                        }                        
                    }
                }
            }
        }
        
        return result;
    }
};