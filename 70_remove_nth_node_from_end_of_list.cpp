/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pre = head, *curr = head;
        
        while(n-- > 0) curr = curr->next;
        if(curr == NULL)
        {
            head = head->next;
            free(pre);
            return head;
        }
        
        while(curr->next != NULL)
        {
            pre = pre->next;
            curr = curr->next;
        }
        
        ListNode *tmp = pre->next;
        pre->next = pre->next->next;
        free(tmp);
        
        return head;
    }
};