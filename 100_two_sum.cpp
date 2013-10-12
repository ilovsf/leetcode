struct node
{
    int index;
    int val;
};

bool compare(const node *n1, const node *n2)
{
    return n1->val < n2->val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node *> tmp(numbers.size());
        vector<int> result(2);
        
        for(int i = 0; i < numbers.size(); ++ i)
        {
            node *n = new node;
            n->val = numbers[i];
            n->index = i + 1;
            tmp[i] = n;
        }
        
        sort(tmp.begin(), tmp.end(), compare);
        
        int begin = 0, end = tmp.size() - 1;
        while(begin < end)
        {
            if(tmp[begin]->val + tmp[end]->val < target)
            {
                ++ begin;
            }
            else if(tmp[begin]->val + tmp[end]->val > target)
            {
                -- end;
            }
            else
            {
                result[0] = tmp[begin]->index;
                result[1] = tmp[end]->index;
                break;
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};