class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool sign = true;
        if(x < 0) sign = false;
        
        int tmp = abs(x);
        int digit = 0;
        while(tmp > 0)
        {
            digit *= 10;
            digit += tmp % 10;
            tmp /= 10;
        }
        
        return sign ? digit : -1 * digit;
    }
};