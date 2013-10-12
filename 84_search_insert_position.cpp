class Solution {
public:
    //return the first element that greater than or equal to the target
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
        int size = n;
        
        while(size > 0)
        {
            int half = size / 2;
            int mid = index + half;
            if(A[mid] < target)
            {
                index = mid + 1;
                size = size - half - 1;
            }
            else
            {
                size = half;
            }
        }
        
        return index;
    }
};