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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head, *tmp1 = l1, *tmp2 = l2, *tmp_sum;
        int count = 1, carry = 0;
        while(tmp1 != NULL || tmp2 != NULL)
        {
            int sum = carry;
            if(tmp1 != NULL)
            {
                sum += tmp1->val;
                tmp1 = tmp1->next;
            }
            if(tmp2 != NULL)
            {
                sum += tmp2->val;
                tmp2 = tmp2->next;
            }            
            carry = sum / 10;
            
            ListNode *tmp_node = new ListNode(sum % 10);
            if(count == 1)
            {
                head = tmp_node;
                tmp_sum = head;
            }
            else
            {
                tmp_sum->next = tmp_node;
                tmp_sum = tmp_sum->next;
            }
            
            count += 1;
        }
        
        if(carry > 0)
        {
            ListNode *tmp_node = new ListNode(carry);
            tmp_sum->next = tmp_node;
        }
        
        return head;
    }
};