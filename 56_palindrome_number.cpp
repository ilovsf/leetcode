class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x < 0) return false;
        
        int tmp = x;
        
        int digit = 0;
        while(tmp > 0)
        {
            digit *= 10;
            digit += tmp % 10;
            tmp /= 10;
        }
        
        return digit == x;
    }
};