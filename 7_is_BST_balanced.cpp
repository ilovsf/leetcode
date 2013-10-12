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
    bool checkBalanced(TreeNode *root, int &height){
        if(root == NULL) return true;
        
        int lh, rh;
        int result = true;
        if(root->left != NULL)
        {
            result &= checkBalanced(root->left, lh);
        }
        else
        {
            lh = -1;
        }
        
        if(root->right != NULL)
        {
            result &= checkBalanced(root->right, rh);
        }
        else
        {
            rh = -1;
        }
        
        height = 1 + max(lh, rh);
        
        if(lh - rh >= -1 && lh - rh <= 1) return result;
        else return false;
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height;
        return checkBalanced(root, height);
    }
};