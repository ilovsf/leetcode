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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return NULL;
        if(m == n) return head;
        
        ListNode *result = new ListNode(0);
        result->next = head;
        head = result;
        
        ListNode *m_head = result->next;
        for(int i = 1; i < m; ++ i)
        {
            result = result->next;
            m_head = m_head->next;
        }
        
        ListNode *n_head = m_head;
        for(int i = 0; i <= n - m; ++ i)
        {
            n_head = n_head->next;
        }
        
        ListNode *tmp = m_head->next;
        ListNode *tmp_res = m_head;
        while(tmp != n_head)
        {
            m_head->next = tmp->next;
            tmp->next = tmp_res;
            tmp_res = tmp;
            tmp = m_head->next;
        }
        result->next = tmp_res;
        
        return head->next;
    }
};