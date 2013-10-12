class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // using long long type to avoid overflow
        long long a = dividend;
        long long b = divisor;
        
        if(b == 0)
            return -1;
        
        bool negative = false;
        if(a < 0)
        {
            a = -1 * a;
            negative ^= true;
        }
        if(b < 0)
        {
            b = -1 * b;
            negative ^= true;
        }
        
        //decide how far to move from b to a
        int bit_move = 0;
        while((b << bit_move) <= a)
        {
            ++ bit_move;
        }
        
        int result = 0;
        for(int i = bit_move; i >= 0; -- i)
        {
            if((b << i) <= a)
            {
                result |= 1 << i;
                a -= b << i;
            }
        }
        
        if(negative)
            return result * (-1);
        return result;
    }
};