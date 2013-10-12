class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        
        int height = grid.size();
        int width = grid[0].size();
        
        for(int i = 1; i < height; ++ i)
        {
            grid[i][0] += grid[i - 1][0];
        }
        
        for(int i = 1; i < width; ++ i)
        {
            grid[0][i] += grid[0][i - 1];
        }
        
        for(int i = 1; i < height; ++ i)
        {
            for(int j = 1; j < width; ++ j)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[height - 1][width - 1];
    }
};