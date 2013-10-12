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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *less = new ListNode(-1);
        ListNode *greater = new ListNode(-1);
        ListNode *pLess = less, *pGreater = greater;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                pLess->next = head;
                pLess = pLess->next;
            }
            else
            {
                pGreater->next = head;
                pGreater = pGreater->next;
            }
            head = head->next;
        }
        
        pGreater->next = NULL;
        pLess->next = greater->next;
        
        return less->next;
    }
};