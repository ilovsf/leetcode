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
    ListNode *reverseKNodes(ListNode *head, int k)
    {
        ListNode *result = new ListNode(0);
        result->next = head;
        ListNode *first = head;
        
        ListNode *curr = first;
        while( curr != NULL && k-- > 0) curr = curr->next;
        if(k > 0) return head;
        
        ListNode *tmp = first->next;
        ListNode *res = first;
        while(tmp != curr)
        {
            first->next = tmp->next;
            tmp->next = res;
            res = tmp;
            tmp = first->next;
        }
        result->next = res;
        return result->next;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || k == 1) return head;
        
        ListNode *result = new ListNode(0);
        result->next = head;
        
        ListNode *index = head;
        head = result;
        
        while(true)
        {
            result->next = reverseKNodes(index, k);
            for(int i = 0;i < k && result != NULL; ++ i)
            {
                result = result->next;
            }
            
            if(result == NULL) break;
            index = result->next;
        }
        
        return head->next;
    }
};