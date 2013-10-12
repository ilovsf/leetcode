class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int height = matrix.size();
        int width = matrix[0].size();
        int size = height * width;
        
        int left = 0, right = size - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            int val = matrix[mid / width][mid % width];
            if(target == val)
            {
                return true;
            }
            else if(target > val)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};