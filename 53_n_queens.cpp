class Solution {
public:
    int *queue_position;
    
    bool isSafe(int index)
    {
        int curr_pos = queue_position[index];
        for(int i = 0; i < index; ++ i)
        {
            if(curr_pos == queue_position[i]) return false;
            if(abs(curr_pos - queue_position[i]) == index - i) return false;
        }
        
        return true;
    }
    
    void dfsNQueens(int index, int N, vector<vector<string> > &res){
        if(index >= N)
        {
            //convert a solution to a vector<string> and push it back to res
            string str(N, '.');
            vector<string> curr_res(N, str);
            for(int i = 0; i < N; ++ i)
            {
                curr_res[i].at(queue_position[i]) = 'Q';
            }
            
            res.push_back(curr_res);
        }
        else
        {
            for(int i = 0; i < N; ++ i)
            {
                queue_position[index] = i;
                if(isSafe(index)) dfsNQueens(index + 1, N, res);
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > result;
        if(n == 0) return result;
        
        queue_position = new int[n];
        dfsNQueens(0, n, result);
        
        return result;
    }
};