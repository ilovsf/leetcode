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
    map<int, int> inorder_hash;
    
	//pos是为了方便查找hash表中的相对位置，所以pos总是相对原始inorder数组中的值
    TreeNode *buildBSTree(int *inorder, int *postorder, int size, int pos){
        if(size == 0) return NULL;
        
        int root_val = postorder[size - 1];
        TreeNode *root = new TreeNode(root_val);
        int inorder_index = inorder_hash[root_val] - pos;
        root->left = buildBSTree(inorder, postorder, inorder_index, pos);
        root->right = buildBSTree(inorder + inorder_index + 1, postorder + inorder_index, size - 1 - inorder_index, pos + inorder_index + 1);
        
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size() == 0 || postorder.size() == 0 
            || inorder.size() != postorder.size())
        {
            return NULL;
        }
        
        int tree_size = inorder.size();
        int *inorder_arr = new int[tree_size];
        int *postorder_arr = new int[tree_size];
        
        for(int i = 0; i < tree_size; ++ i)
        {
            inorder_arr[i] = inorder[i];
            postorder_arr[i] = postorder[i];
            inorder_hash[inorder[i]] = i;
        }
        
        return buildBSTree(inorder_arr, postorder_arr, tree_size, 0);
    }
};