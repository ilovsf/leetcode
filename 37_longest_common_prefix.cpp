class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(strs.size() == 0) return "";
        
        int array_size = strs.size();
        string prefix = "";
        int index = 0;
        
        bool flag = true;
        while(true)
        {
            if(index >= strs[0].size()) break;
            
            char s = strs[0].at(index);
            for(int i = 1; i < array_size; ++ i)
            {
                if(index >= strs[i].size() || strs[i].at(index) != s)
                {
                    flag = false;
                }
            }
            
            if(flag) prefix.insert(prefix.end(), s);
            else break;
            
            ++ index;
        }
        
        return prefix;
    }
};