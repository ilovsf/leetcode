class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        for(int i = 0; i < n; ++ i)
        {
            vector<int> tmp(n);
            result.push_back(tmp);
        }
        
        int k = 1;
        for(int r = 0; r < n / 2; ++ r)
        {
            for(int index = r; index < n - 1 - r; ++ index)
            {
                result[r][index] = k ++;
            }
            for(int index = r; index < n - 1 - r; ++ index)
            {
                result[index][n - 1 - r] = k ++;
            }
            for(int index = r; index < n - 1 - r; ++ index)
            {
                result[n - 1 - r][n - 1 - index] = k ++;
            }
            for(int index = r; index < n - 1 - r; ++ index)
            {
                result[n - 1 - index][r] = k ++;
            }
        }
        
        if(n % 2 == 1) result[n / 2][n / 2] = k;
        
        return result;
    }
};