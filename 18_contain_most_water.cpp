class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int array_size = height.size();
        int left = 0, right = array_size - 1;
        
        int max = -1;
        while(left < right)
        {
            int min;
            if(height[left] > height[right])
            {
                min = height[right];
                right --;
            }
            else
            {
                min = height[left];
                left ++;
            }
            int area = min * (right - left + 1);
            if(area > max)
            {
                max = area;
            }
        }
        
        return max;
    }
};