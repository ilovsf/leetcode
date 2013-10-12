class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
		
		//去除前导空格
        while(*s == ' ') ++ s;
        
		//开头可以有一位+/-号
        if(*s == '-' || *s == '+') ++ s;
        
		//has_E: 出现e/E
		//has_dot：出现小数点
		//has_digit：出现数字
        bool has_E = false, has_dot = false, has_digit = false;
        while(*s != '\0' && *s != ' ')
        {
            char ch = *s;
            int digit = ch - '0';
            
            if(digit < 0 || digit > 9)
            {
                if(ch == '.')
                {
					//出现小数点时，之前不允许出现E或小数点
                    if(has_dot || has_E) return false;
                    else has_dot = true;
                }
                
                else if(ch == 'e' || ch == 'E')
                {
					//出现E时，之前不允许出现E，且必须出现数字
                    if(has_E || !has_digit) return false;
                    else has_E = true;
                }
                
				//出现正负号，必须紧接着E
                else if(ch == '+' || ch == '-')
                {
                    if(*(s - 1) != 'e' && *(s - 1) != 'E') return false;
                }
                
                else
                {
                    return false;
                }
            }
            else
            {
                has_digit = true;
            }
            ++ s;
        }
        
		//E/e不能是结尾
        if(*(s-1) == 'E'||*(s-1) == 'e' || *(s-1) == '+' || *(s-1) == '-') return false;
		//后面必须是连续的空格，不能有别的符号
        while(*s != '\0' && *s == ' ') ++s;
        if(*s != '\0') return false;
        
        return has_digit;
    }
};