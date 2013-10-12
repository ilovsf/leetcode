class Solution {
#include <stack>

public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == "") return 0;
        
        int str_size = s.size();
        stack<int> parenthese_stack;
        
        int max = 0;
        int count = 0;
        for(int i = 0; i < str_size; ++ i)
        {
            if(s.at(i) == '(')
            {
                parenthese_stack.push(count);
            }
            else
            {
                //invaid, just skip
                if(parenthese_stack.empty()) 
                {
                    count = 0;
                }
                else
                {
                    parenthese_stack.pop();
                    count += 2;
                    int tmp = count;
                    if(!parenthese_stack.empty())
                    {
                        tmp -= parenthese_stack.top();
                    }
                    if(tmp > max) max = tmp;
                    
                }
            }
        }
        
        return max;
    }
};