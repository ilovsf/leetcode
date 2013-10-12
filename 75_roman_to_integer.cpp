class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> hash;
        hash['M'] = 1000;
        hash['D'] = 500;
        hash['C'] = 100;
        hash['L'] = 50;
        hash['X'] = 10;
        hash['V'] = 5;
        hash['I'] = 1;
        
        int size = s.size();
        int result = 0;
        int prev = 1001;
        
        for(int i = 0; i < size; ++ i)
        {
            int curr = hash[s[i]];
            if(curr <= prev)
            {
                result += curr;
            }
            else
            {
                result += curr;
                result -= 2 * prev;
            }
            prev = curr;
        }
        
        return result;
    }
};