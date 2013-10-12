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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(root == NULL) return result;
        
        queue<TreeNode *> q;
        q.push(root);
        
        int level_num = 1, count = 0;
        
        bool left_to_right = true;
        while(! q.empty())
        {
            int tmp = 0;
            vector<int> curr_res;
            while(count < level_num)
            {
                TreeNode *front_node = q.front();
                if(front_node->left != NULL)
                {
                    q.push(front_node->left);
                    ++ tmp;
                }
                if(front_node->right != NULL)
                {
                    q.push(front_node->right);
                    ++ tmp;
                }
                curr_res.push_back(front_node->val);
                q.pop();
                ++ count;
            }
            if(! left_to_right)
            {
                reverse(curr_res.begin(), curr_res.end());
            }
            result.push_back(curr_res);
            level_num = tmp;
            count = 0;
            left_to_right ^= true;
        }
        
        return result;
    }
};