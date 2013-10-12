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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        if(root == NULL)
            return result;
        
        if(root->left != NULL)
        {
            vector<int> tmp = inorderTraversal(root->left);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        result.push_back(root->val);
        if(root->right != NULL)
        {
            vector<int> tmp = inorderTraversal(root->right);
            result.insert(result.end(), tmp.begin(), tmp.end());
        }
        
        return result;
    }
};