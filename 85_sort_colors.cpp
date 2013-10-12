class Solution {
public:
    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || A == NULL) return;
        
        int left = -1, right = n;
        int index = 0;
        
        while(index < right)
        {
            if(A[index] == 2)
            {
                swap(A + index, A + (--right));
            }
            else if(A[index] == 1)
            {
                ++ index;
            }
            else
            {
                swap(A + index ++, A + (++ left));
            }
        }
    }
};