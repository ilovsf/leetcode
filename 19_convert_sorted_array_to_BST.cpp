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
    TreeNode *generateBST(int *array, int size){
        if(size <= 0) return NULL;
        if(size == 1) return new TreeNode(*array);
        
        int left = 0, right = size - 1;
        int mid = (left + right) >> 1;
        int left_num = mid - left;
        int right_num = right - mid;
        
        TreeNode *root = new TreeNode(*(array + mid));
        root->left = generateBST(array, left_num);
        root->right = generateBST(array + mid + 1, right_num);
        
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = num.size();
        int *array = new int[size];
        for(int i = 0; i < size; ++ i)
        {
            array[i] = num[i];
        }
        
        
        return generateBST(array, size);
    }
};