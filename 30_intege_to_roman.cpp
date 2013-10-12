class Solution {
public:
    //this function is used to generate a single digit in Roman style
    string digitRoman(int num, char ten, char five, char one)
    {
        stringstream oss;
        
        if(num == 9)
        {
            oss << one;
            oss << ten;
        }
        else if(num >= 5)
        {
            oss << five;
            while(num-- > 5) oss << one;
        }
        else if(num == 4)
        {
            oss << one;
            oss << five;
        }
        else if(num < 4)
        {
            while(num-- > 0) oss << one;
        }
        
        return oss.str();
    }

    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        stringstream result;
        
        if(num > 0)
        {
            result << digitRoman(num / 1000 % 10, ' ', ' ', 'M');
            result << digitRoman(num / 100 % 10, 'M', 'D', 'C');
            result << digitRoman(num / 10 % 10, 'C', 'L', 'X');
            result << digitRoman(num % 10, 'X', 'V', 'I');
        }
        
        return result.str();
    }
};