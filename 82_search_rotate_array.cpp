class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1;
        if(n == 0 || NULL == A) return -1;
        if(n == 1) return A[0] == target ? 0 : -1;

        //at least three numbers
        while(left < right - 1)
        {
            int mid = (left + right) / 2;
            if(target == A[mid]) return mid;
            
            if(A[mid] > A[left] && A[left] > A[right])
            {
                if(target > A[mid])
                {
                    left = mid;
                }
                else
                {
                    if(target >= A[left])
                    {
                        right = mid;
                    }
                    else
                    {
                        left = mid;
                    }
                }
            }
            else if(A[mid] < A[right] && A[right] < A[left])
            {
                if(target < A[mid])
                {
                    right = mid;
                }
                else
                {
                    if(target <= A[right])
                    {
                        left = mid;
                    }
                    else
                    {
                        right = mid;
                    }
                }
            }
            else
            {
                if(target > A[mid])
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
        }
        
        if(A[left] == target) return left;
        if(A[right] == target) return right;
        return -1;
    }

    int simple_search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1;
        if(n == 0 || NULL == A) return -1;
        if(n == 1) return A[0] == target ? 0 : -1;

        //at least three numbers
        while(left < right - 1)
        {
            int mid = (left + right) / 2;
            if(target == A[mid]) return mid;
            
            if(A[mid] > A[right])
            {
                if(target > A[mid] || target < A[left])
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            else if(A[mid] < A[left])
            {
                if(target < A[mid] || target > A[right])
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            else
            {
                if(target > A[mid])
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
        }
        
        if(A[left] == target) return left;
        if(A[right] == target) return right;
        return -1;
    }
};