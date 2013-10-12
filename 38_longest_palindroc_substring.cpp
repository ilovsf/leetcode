class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // re construct the string
        if(s == "") return "";
        
        string ss = "";
        ss.insert(ss.end(), '$');
        for(int i = 0; i < s.size(); ++ i)
        {
            ss.insert(ss.end(), '_');
            ss.insert(ss.end(), s.at(i));
        }
        ss.insert(ss.end(), '_');
        
        int *palindrome_len  = new int[ss.size() + 1];
        palindrome_len[1] = 1;
        palindrome_len[2] = 2;
        int max = 2, max_index = 2, right_most = 2 + (2 - 1);
        
        for(int i = 3; i <= ss.size(); ++ i)
        {
            int j = 2 * max_index - i;
            if(right_most >= i)
            {
                palindrome_len[i] = min(palindrome_len[j], right_most - i + 1);
            }
            else
            {
                palindrome_len[i] = 1;
            }
            
            while(i + palindrome_len[i] <= ss.size() && i - palindrome_len[i] >= 1 
                && ss[i + palindrome_len[i]] == ss[i - palindrome_len[i]])
            {
                palindrome_len[i] ++;
            }
            
            if(palindrome_len[i] > max)
            {
                max = palindrome_len[i];
                max_index = i;
                right_most = i + palindrome_len[i] - 1;
            }
        }
        
        bool is_odd = false;
        if(max % 2 == 0) is_odd = true;
        
        max_index = max_index / 2 - 1;
        max = max / 2;
        
        int pos_begin = max_index - max + 1;
        int length;
        if(is_odd) length = max * 2 -1;
        else length = max * 2;
        
        return s.substr(pos_begin, length);
    }
};