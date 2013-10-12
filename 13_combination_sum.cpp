class Solution {
public:
	//设置参数curr_result，不能为引用变量，否则在深搜的过程中会把过程变量带到回溯中来
    void sum_dfs(vector<int> &candidates, int index, int target, vector<int> curr_result, vector<vector<int> > &result)
    {     
        if(index >= candidates.size())
        {
			//终止条件下，若target=0，则找到组合，加入最终结果
            if(target == 0)
            {
                result.push_back(curr_result);
            }
        }
        
        else
        {
            while(target >= 0)
            {
                sum_dfs(candidates, index + 1, target, curr_result, result);
                curr_result.push_back(candidates[index]);
                target -= candidates[index];
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> tmp;
        
        sort(candidates.begin(), candidates.end());
        sum_dfs(candidates, 0, target, tmp, result);
        
        return result;
    }
};