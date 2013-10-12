class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        int size = digits.size();
        digits[size - 1] += 1;
        int carry = 0;
        
        for(int i = size - 1; i >= 0; -- i)
        {
            result.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        
        if(carry > 0) result.push_back(carry);
        reverse(result.begin(), result.end());
        
        return result;
    }
};