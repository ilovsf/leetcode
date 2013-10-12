class Solution {
public:
    bool isSafe(int *position, int index){
        int curr_pos = position[index];
        
        for(int i =0; i < index; ++ i)
        {
            if(curr_pos == position[i]) return false;
            if(abs(curr_pos - position[i]) == index - i) return false;
        }
        
        return true;
    }
    
    void dfsNQueens(int index, int N, int *pos, int *result)
    {
        if(index >= N)
        {
            (*result) ++;
        }
        else
        {
            for(int i = 0; i < N; ++ i)
            {
                pos[index] = i;
                if(isSafe(pos, index)) dfsNQueens(index + 1, N, pos, result);
            }
        }
    }
    
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        
        int result = 0;
        int *position = new int[n];
        
        dfsNQueens(0, n, position, &result);
        
        return result;
    }
};