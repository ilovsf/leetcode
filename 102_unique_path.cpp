class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total_step = m + n - 2;
        int down_step = min(n - 1, m - 1);
        
        if(down_step == 0) return 1;
        
        long long tmp_total = 1, tmp_down = 1;
        
        while(down_step > 0)
        {
            tmp_down *= down_step --;
            tmp_total *= total_step --;
        }
        
        return tmp_total / tmp_down;
    }
};