class Solution {
#include <stack>
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> paren_stack;
		
		int str_size = s.size();
		if(str_size == 0) return true;
		
		for(int i = 0; i < str_size; ++ i)
		{
			if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
			{
				paren_stack.push(s.at(i));
			}
			else if(s.at(i) == ')')
			{
				if(paren_stack.empty() || paren_stack.top() != '(')
				{
					return false;
				}
				else
				{
					paren_stack.pop();
				}
			}
			else if(s.at(i) == '}')
			{
				if(paren_stack.empty() || paren_stack.top() != '{')
				{
					return false;
				}
				else
				{
					paren_stack.pop();
				}
			}
			else if(s.at(i) == ']')
			{
				if(paren_stack.empty() || paren_stack.top() != '[')
				{
					return false;
				}
				else
				{
					paren_stack.pop();
				}
			}
		}
		
		return paren_stack.empty();
    }
};