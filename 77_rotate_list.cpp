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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = 0;
        if(head == NULL) return NULL;
        
        ListNode *first = head, *second = head;
        
        while(second != NULL)
        {
            second = second->next;
            ++ size;
        }
        
        k = k % size;
        if(k == 0) return head;
        
        second = head;     
        for(int i = 0; i < k; ++ i)
        {
            second = second->next;
        }
        
        while(second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }
        
        ListNode *res = first->next;
        second->next = head;
        first->next = NULL;
        
        return res;
    }
};