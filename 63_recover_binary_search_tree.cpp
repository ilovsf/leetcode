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
    void inorderTraverse(TreeNode *root, vector<int> &nums, vector<TreeNode *> &nodes){
        if(root == NULL) return;
        
        inorderTraverse(root->left, nums, nodes);
        nums.push_back(root->val);
        nodes.push_back(root);
        inorderTraverse(root->right, nums, nodes);
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> numbers;
        vector<TreeNode *> nodes;
        inorderTraverse(root, numbers, nodes);
        
        int first, second;
        int size = numbers.size();
        
        for(int i = 0; i < size - 1; ++ i)
        {
            if(numbers[i] >= numbers[i+1])
            {
                first = i;
                break;
            }
        }
        for(int i = size - 1; i > 0; -- i)
        {
            if(numbers[i] <= numbers[i-1])
            {
                second = i;
                break;
            }
        }
        
        nodes[first]->val = numbers[second];
        nodes[second]->val = numbers[first];
    }
};