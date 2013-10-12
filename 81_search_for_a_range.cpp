class Solution {
public:
	// return the first index of element whose value is greater than or equal to the target
    int lowerBound(int A[], int size, int target){
        int len = size;
        int first = 0;
        
        while(len > 0)
        {
            int half = len / 2;
            int mid = first + half;
            if(A[mid] < target)
            {
                first = mid + 1;
                len = len - half - 1;
            }
            else
            {
                len = half;
            }
        }
        
        return first;
    }
    
	//return the first index of the element whose value is greater than the target
    int upperBound(int A[], int size, int target){
        int len = size;
        int first = 0;
        
        while(len > 0)
        {
            int half = len / 2;
            int mid = first + half;
            if(A[mid] > target)
            {
                len = half;
            }
            else
            {
                first = mid + 1;
                len = len - half - 1;
            }
        }
        
        return first;
    }

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if(n == 0) return result;
        
        int left_bound = lowerBound(A, n, target);
        int right_bound = upperBound(A, n, target) - 1;
        
        if(A[left_bound] == target && A[right_bound] == target)
        {
            result.push_back(left_bound);
            result.push_back(right_bound);
        }
        else
        {
            result.push_back(-1);
            result.push_back(-1);            
        }
        
        return result;
    }
};