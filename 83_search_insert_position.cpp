class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || NULL == A) return 0;
        
        int left = 0, right = n - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(A[mid] == target) return mid;
            
            if(target > A[mid]) left = mid + 1;
            else right = mid - 1;
        }
        
        if(target <= A[left]) return left;
        if(target > A[left]) return left + 1;
    }
};