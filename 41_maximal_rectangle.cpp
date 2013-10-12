class Solution {

struct node{
    int index;
	int height;
};
#include <stack>
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(matrix.size() == 0) return 0;
        
        int main_len = matrix.size();
        int sub_len = matrix[0].size();
        int *array = new int[sub_len + 1];
        memset(array, 0, sizeof(int) * (sub_len + 1));
        
        int max_area = 0;
        
        for(int i = 0; i < main_len; ++ i)
        {
			// update the array
            for(int j = 0; j < sub_len; ++ j)
            {
                if(matrix[i][j] == '0')
				{
					array[j] = 0;
				}
				else
				{
					array[j] ++;
				}
            }
			
			stack<node *> node_stack;
			int local_max_area = 0;
			for(int j = 0; j <= sub_len; ++ j)
			{
				node *new_node = new node;
				new_node->height = array[j];
				if(node_stack.empty() || array[j] >= node_stack.top()->height)
				{
					new_node->index = j;
				}
				else
				{
					int index, height;
					while(!node_stack.empty() && node_stack.top()->height > array[j])
					{
						index = node_stack.top()->index;
						height = node_stack.top()->height;
						int area = (j - index) * height;
						if(area > local_max_area)
						{
							local_max_area = area;
						}
                        node_stack.pop();
					}
					new_node->index = index;
				}
				node_stack.push(new_node);
			}
			if(local_max_area > max_area)
			{
				max_area = local_max_area;
			}
        }
        
        return max_area;
    }
};