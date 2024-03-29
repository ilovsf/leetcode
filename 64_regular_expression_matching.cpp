﻿class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(*p == '\0') return *s == '\0';
        
        if(*(p+1) == '*')
        {
            while(*s == *p || (*p == '.' && *s != '\0'))
            {
                if(isMatch(s++, p+2)) return true;
            }
            
            return isMatch(s, p+2);
        }
        else
        {
            if(*s == *p || (*p == '.' && *s != '\0')) return isMatch(s+1, p+1);
            else return false;
        }
    }
};