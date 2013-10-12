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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *result = NULL, *tmp_res;
        
        bool is_head = true;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                if(is_head)
                {
                    is_head = false;
                    result = l1;
                    tmp_res = l1;
                }
                else
                {
                    tmp_res->next = l1;
                    tmp_res = tmp_res->next;
                }
                l1 = l1->next;
            }
            else
            {
                if(is_head)
                {
                    is_head = false;
                    result = l2;
                    tmp_res = l2;
                }
                else
                {
                    tmp_res->next = l2;
                    tmp_res = tmp_res->next;
                }
                l2 = l2->next;
            }
        }
        
        while(l1 != NULL)
        {
            if(is_head)
            {
                is_head = false;
                result = l1;
                tmp_res = l1;
            }
            else
            {
               tmp_res->next = l1;
               tmp_res = tmp_res->next;
            }
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            if(is_head)
            {
                is_head = false;
                result = l2;
                tmp_res = l2;
            }
            else
            {
                tmp_res->next = l2;
                tmp_res = tmp_res->next;
            }
            l2 = l2->next;
        }
        
        return result;
    }
};