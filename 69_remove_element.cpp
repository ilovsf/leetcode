class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result = 0;
        
        int right = n - 1;
        int left = 0;
        while(left <= right)
        {
            if(A[left] == elem)
            {
                swap(A[left], A[right --]);
            }
            else
            {
                ++ result;
                ++ left;
            }
        }
        
        return result;
    }
};