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
    bool isEveryNodeNULL(vector<bool> &is_null){
        for(int i = 0; i < is_null.size(); ++ i)
        {
            if(!is_null[i]) return false;
        }
        
        return true;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lists_size = lists.size();
        if(lists_size == 0) return NULL;
        
        ListNode *head = NULL, *tmp;
        bool is_head = true;
        vector<bool> is_null(lists_size, false);
        while(! isEveryNodeNULL(is_null))
        {
            int min_val = INT_MAX;
            int min_index = 0;
            for(int i = 0; i < lists_size; ++ i)
            {
                if(is_null[i]) continue;
                if(lists[i] == NULL)
                {
                    is_null[i] = true;
                }
                else
                {
                    if(lists[i]->val < min_val)
                    {
                        min_val = lists[i]->val;
                        min_index = i;
                    }
                }
            }
            
            if(is_head)
            {
                head = lists[min_index];
                tmp = head;
                is_head = false;
            }
            else
            {
                tmp->next = lists[min_index];
                tmp = tmp->next;
            }
            
            if(lists[min_index] != NULL) lists[min_index] = lists[min_index]->next;
        }
        
        return head;
    }
};