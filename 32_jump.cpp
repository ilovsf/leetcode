class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
        while(index < n && A[index] > 0)
        {
            index += A[index];
        }
        
        if(index >= n - 1) return true;
        return false;
    }
};