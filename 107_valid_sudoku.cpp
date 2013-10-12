class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<char> hash;
        for(int i = 0; i < 9; ++ i)
        {
            hash.clear();
            for(int j = 0;j < 9; ++ j)
            {
                char curr = board[i][j];
                if(curr != '.')
                {
                    if(hash.count(curr) == 1) return false;
                    else hash.insert(curr);
                }
            }
        }
        
        for(int i = 0; i < 9; ++ i)
        {
            hash.clear();
            for(int j = 0; j < 9; ++ j)
            {
                char curr = board[j][i];
                if(curr != '.')
                {
                    if(hash.count(curr) == 1) return false;
                    else hash.insert(curr);
                }
            }
        }
        
        for(int i = 0; i <= 6; i += 3)
        {
            for(int j = 0; j <= 6; j += 3)
            {
                hash.clear();
                for(int k = 0; k < 3; ++ k)
                {
                    for(int t = 0; t < 3; ++ t)
                    {
                        int curr = board[i+k][j+t];
                        if(curr != '.')
                        {
                            if(hash.count(curr) == 1) return false;
                            else hash.insert(curr);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};