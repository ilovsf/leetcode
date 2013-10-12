class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        
        int a = 1, b = 2, result;
        for(int i = 3; i <= n; ++ i)
        {
            result = a + b;
            a = b;
            b = result;
        }
        
        return result;
    }
};