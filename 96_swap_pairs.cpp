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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
        
        if(head->next == NULL) return head;
        
        //at least two nodes
        ListNode *new_head = head->next;
        
        ListNode *tmp1 = head;
        ListNode *tmp2 = head->next;
        
        while(tmp1 != NULL && tmp2 != NULL)
        {
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            
            ListNode *tmp3;
            tmp3 = tmp1;
            tmp1 = tmp1->next;
            
            if(tmp1 != NULL)
            {
                tmp2 = tmp1->next;
                if(tmp2 != NULL) tmp3->next = tmp2;
            }
            else 
            {
                tmp2 = NULL;
            }
        }
        
        return new_head;
    }
};