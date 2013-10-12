class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        
        int curr_ele = A[0];
        int max = curr_ele;
        for(int i = 1; i < n; ++ i)
        {
            if(curr_ele < 0)
            {
                curr_ele = A[i];
            }
            else
            {
                curr_ele += A[i];
            }
            if(curr_ele > max)
            {
                max = curr_ele;
            }
        }
        
        return max;
    }
};