class Solution {
public:
    //define as finding k numbers indexed from index to n
    void combine_dfs(int index, int n, int k, vector<int> &curr_res, vector<vector<int> > &res) {
        if(k <= 0)
        {
            res.push_back(curr_res);
        }
        else
        {
            for(int i = index; i <= n - k + 1; ++ i)
            {
                curr_res.push_back(i);
                combine_dfs(i + 1, n, k - 1, curr_res, res);
                //traceback
                curr_res.pop_back();
            }
        }
    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> tmp;
        
        combine_dfs(1, n ,k, tmp, result);
        
        return result;
    }
};