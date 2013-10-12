class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total_index = m + n - 1;
        int A_index = m - 1;
        int B_index = n - 1;
        
        while(A_index >= 0 && B_index >= 0)
        {
            if(A[A_index] > B[B_index])
            {
                A[total_index --] = A[A_index --];
            }
            else
            {
                A[total_index --] = B[B_index --];
            }
        }
        
        while(A_index >= 0) A[total_index --] = A[A_index --];
        while(B_index >= 0) A[total_index --] = B[B_index --];
    }
};