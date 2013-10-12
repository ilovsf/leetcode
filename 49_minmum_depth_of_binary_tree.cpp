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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) return 0;
        
        if(root->left == NULL || root->right == NULL)
        {
            return 1 + max(minDepth(root->left), minDepth(root->right));
        }
        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};