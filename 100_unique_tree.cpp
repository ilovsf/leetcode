/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<TreeNode *> &res, int left, int right){
        if(left > right)
        {
            res.push_back(NULL);
        }
        else
        {
            for(int i = left; i <= right; ++ i)
            {
                vector<TreeNode *> left_res;
                dfs(left_res, left, i - 1);
                vector<TreeNode *> right_res;
                dfs(right_res, i + 1, right);
                
                for(int j = 0; j < left_res.size(); ++ j)
                {
                    for(int k = 0; k < right_res.size(); ++ k)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_res[j];
                        root->right = right_res[k];
                        res.push_back(root);
                    }
                }
            }
        }
    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> result;    
        dfs(result, 1, n);
        
        return result;
    }
};    