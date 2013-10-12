class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1;
        
        int index = 0;
        while(index <= right)
        {
            if(A[index] == 2)
            {
                swap(A[index], A[right --]);
            }
            else if(A[index] == 0)
            {
                swap(A[index ++], A[left ++]);
            }
            else
            {
                index ++;
            }
        }
    }
};