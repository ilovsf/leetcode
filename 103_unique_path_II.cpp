class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(obstacleGrid.size() == 0) return 0;
        if(obstacleGrid[0].size() == 0) return 0;
        
        int grid_height = obstacleGrid.size();
        int grid_width = obstacleGrid[0].size();
        
        int opt[grid_height][grid_width];
        
        if(obstacleGrid[0][0] == 0) opt[0][0] = 1;
        else opt[0][0] = 0
        
        for(int i = 1; i < grid_height; ++ i)
        {
            if(obstacleGrid[i][0] == 1) opt[i][0] = 0;
            else opt[i][0] = opt[i - 1][0];
        }
        
        for(int i = 1; i < grid_width; ++ i)
        {
            if(obstacleGrid[0][i] == 1) opt[0][i] = 0;
            else opt[0][i] = opt[0][ i - 1];
        }
        
        for(int i = 1; i < grid_height; ++ i)
        {
            for(int j = 1; j < grid_width; ++ j)
            {
                if(obstacleGrid[i][j] == 1) opt[i][j] = 0;
                else opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
            }
        }
        
        return opt[grid_height - 1][grid_width - 1];
    }
};