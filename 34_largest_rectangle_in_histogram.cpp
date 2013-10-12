class Solution {
#include <stack>
struct node
{
    int index;
    int height;
};
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<node *> stack;
        height.push_back(0);
        int array_size = height.size();
        
        int max = 0;
        
        for(int i = 0; i < array_size; ++ i)
        {
            node *new_node = new node();
            new_node->height = height[i];
            
            if(stack.empty() || height[i] >= stack.top()->height)
            {
                new_node->index = i;
            }
            else
            {
                int index, h;
                while(!stack.empty() && stack.top()->height > height[i])
                {
                    index = stack.top()->index;
                    h = stack.top()->height;
                    int area = (i - index) * h;
                    if(area > max) max = area;
                    
                    stack.pop();
                }
                new_node->index = index;        
            }
            stack.push(new_node);
        }
        
        return max;
    }
};