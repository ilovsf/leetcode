class Solution {
public:
    bool findWord(vector<vector<char> > &board, vector<vector<bool> > &check, int x, int y, string word)
    {
        if(word.size() == 0) return true;
        
        int board_height = board.size();
        int board_width = board[0].size();
        
        bool result = false;
        if(x > 0)
        {
            if(check[x - 1][y] && board[x - 1][y] == word.at(0)) 
            {
                check[x - 1][y] = false;
                result |= findWord(board, check, x - 1, y, word.substr(1));
            }
        }
        
        if(x < board_height - 1)
        {
            if(check[x + 1][y] && board[x + 1][y] == word.at(0))
            {
                check[x + 1][y] = false;
                result |= findWord(board, check, x + 1, y, word.substr(1));
            }
        }
        
        if(y > 0)
        {
            if(check[x][y - 1] && board[x][y - 1] == word.at(0)) 
            {
                check[x][y - 1] = false;
                result |= findWord(board, check, x, y - 1, word.substr(1));
            }
        }
        
        if(y < board_width - 1)
        {
            if(check[x][y + 1] && board[x][y + 1] == word.at(0)) 
            {
                check[x][y + 1] = false;
                result |= findWord(board, check, x, y + 1, word.substr(1));
            }
        }
        
        return result;
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(board.size() == 0 || word.size() == 0) return true;
        
        char first = word.at(0);
        vector<pair<int, int> > index;
        int board_height = board.size();
        int board_width = board[0].size();
        
        if(board_height * board_width < word.size()) return false;

        
        //find first char
        for(int i = 0; i < board_height; ++ i)
        {
            for(int j = 0; j < board_width; ++ j)
            {
                if(board[i][j] == first) index.push_back(make_pair(i, j));
            }
        }
        
        if(index.size() == 0) return false;
        
        for(vector<pair<int, int> >::iterator it = index.begin(); it != index.end(); ++ it)
        {
            //begin to search at (i, j)
            int x = it->first, y = it->second;
                    
            vector<vector<bool> > check;
            for(int j = 0; j < board_height; ++ j)
            {
                vector<bool> tmp(board_width, true);
                check.push_back(tmp);
            }
            
            check[x][y] = false;
                
            if(findWord(board, check, x, y, word.substr(1)))
            {
                return true;
            }
        }
        
        return false;
    }
};