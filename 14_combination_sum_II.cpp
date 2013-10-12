class Solution {
public:
    void sum_dfs(vector<int> &num, int index, int target, vector<int> curr_res, vector<vector<int> > &res, set<vector<int> > &dict)
    {
        if(index >= num.size())
        {
            if(target == 0)
            {
                if(!dict.count(curr_res))
                {
                    dict.insert(curr_res);
                    res.push_back(curr_res);
                }
            }
        }
        else
        {
            sum_dfs(num, index + 1, target, curr_res, res, dict);
            if(target >= 0)
            {
                target -= num[index];
                curr_res.push_back(num[index]);
                sum_dfs(num, index + 1, target, curr_res, res, dict);
            }
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<vector<int> > dict;
        vector<vector<int> > result;
        vector<int> tmp;
        sort(num.begin(), num.end(), less<int>());
        sum_dfs(num, 0, target, tmp, result, dict);
        
        return result;
    }
};