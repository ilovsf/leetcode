/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    //head should be TreeNode *& type to record the current position
    TreeNode *generateBST(ListNode *& head, int left, int right){
        if(left > right) return NULL;
        
        int mid = left + (right - left) / 2;
        TreeNode *left_child = generateBST(head, left, mid - 1);
        //在此之前其实head已经移动了mid - 1次
        TreeNode *root = new TreeNode(head->val);
        root->left= left_child;
        //move the head
        head = head->next;
        root->right = generateBST(head, mid + 1, right);   
        
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nSize = 0;
        ListNode *tmp = head;
        while(tmp != NULL)
        {
            ++ nSize;
            tmp = tmp->next;
        }
        
        return generateBST(head, 0, nSize - 1);
    }
};