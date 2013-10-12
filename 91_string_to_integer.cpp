class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        while(*str == ' ') ++ str;
        
        int sign = 1;
        if(*str == '-')
        {
            str ++;
            sign = -1;
        }
        else if(*str == '+')
        {
            str ++;
        }
        
        while(*str == '0') ++ str;
        
        long long result = 0;
        while(*str != '\0')
        {
            int ch = *str - '0';
            if(ch < 0 || ch > 9) break;
            result *= 10;
            result += ch;
            ++ str;
        }
        
        if(sign == 1 &&result > INT_MAX) return INT_MAX;
        if(sign == -1 && -result < INT_MIN) return INT_MIN;
        
        if(sign == -1) result = -result;
        return result;
    }
};