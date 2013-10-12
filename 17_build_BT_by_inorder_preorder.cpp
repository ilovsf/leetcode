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
    map<int, int> hash;

    TreeNode *buildTree(int *preorder, int *inorder, int size, int offset){
        if(size == 0) return NULL;
        
        int root_val = preorder[0];
        TreeNode *root = new TreeNode(root_val);
        int index = hash[root_val] - offset;
        root->left = buildTree(preorder + 1, inorder, index, offset);
        root->right = buildTree(preorder + 1 + index, inorder + index + 1, size - 1- index, offset + index + 1);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int preorder_size = preorder.size();
        int inorder_size = inorder.size();
        
        if(preorder_size != inorder_size) return NULL;
        
        int *preorder_arr = new int[preorder_size];
        int *inorder_arr = new int[inorder_size];
        
        for(int i = 0; i < preorder_size; ++ i)
        {
            preorder_arr[i] = preorder[i];
            inorder_arr[i] = inorder[i];
            hash[inorder[i]] = i;
        }
        
        return buildTree(preorder_arr, inorder_arr, inorder_size, 0);
    }
};