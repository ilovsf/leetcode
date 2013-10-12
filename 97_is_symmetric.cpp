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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        
        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        
        return false;
    }
    
    TreeNode *mirrorTree(TreeNode *root)
    {
        if(root == NULL) return NULL;
        
        TreeNode *res = new TreeNode(root->val);
        res->right = mirrorTree(root->left);
        res->left = mirrorTree(root->right);
        
        return res;
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *mirror = mirrorTree(root);
        return isSameTree(root, mirror);
    }
};