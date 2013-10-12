class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        
        int first_index = size - 2;
        while(first_index >= 0 && num[first_index] >= num[first_index + 1]) -- first_index;
        if(first_index >= 0)
        {
            int second_index = size - 1;
            while(second_index >= 0 && num[first_index] >= num[second_index]) -- second_index;
            
            if(second_index >= 0)
            {
                swap(num[first_index], num[second_index]);
                reverse(num.begin() + first_index + 1, num.end());
            }
        }
        else
        {
            reverse(num.begin(), num.end());
        }
    }
};