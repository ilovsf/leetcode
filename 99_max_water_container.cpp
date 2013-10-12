class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A == NULL || n == 0) return 0;
        
        int *max_left = new int[n];
        int *max_right = new int[n];
        
        int result = 0;
        
        max_left[0] = 0;     
        int tmp_max = A[0];
        for(int i = 1; i < n; ++ i)
        {
            max_left[i] = tmp_max;
            if(A[i] > tmp_max) tmp_max = A[i];
        }
        
        max_right[n - 1] = 0;
        tmp_max = A[n - 1];
        for(int i = n - 2; i >= 0; -- i)
        {
            max_right[i] = tmp_max;
            if(A[i] > tmp_max) tmp_max = A[i];
        }
        
        for(int i = 0; i < n; ++ i)
        {
            result += max(0, min(max_left[i], max_right[i]) - A[i]);
        }
        
        return result;
    }
};