class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int num1_size = num1.size(); 
        int num2_size = num2.size();
        
        int *temp = new int[num1_size + num2_size];
        memset(temp, 0, sizeof(int) * (num1_size + num2_size));
        
        for(int i = 0; i < num1.size(); ++ i)
        {
            for(int j = 0; j < num2.size(); ++ j)
            {
                temp[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        string result;
        int carry = 0;
        for(int i = 0; i < num1_size + num2_size; ++ i)
        {
            char ch = (temp[i] + carry) % 10 + '0';
            result.insert(result.begin(), ch);
            carry = (temp[i] + carry) / 10;
        }
        
        while(carry > 0)
        {
            char ch = carry % 10 + '0';
            result.insert(result.begin(), ch);
            carry /= 10;
        }
        
        int index = 0;
        while(index < result.size() && result.at(index) == '0') ++ index;
        
        if(index == result.size()) return "0";
        
        return result.substr(index);
    }
};