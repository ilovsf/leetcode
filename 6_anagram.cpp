class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, string> dict;
        set<string> duplicate;
        vector<string> result;
        
        vector<string>::const_iterator iter = strs.begin();
        while(iter != strs.end())
        {
            string word = *iter;
            string tmp = word;
            // sort tmp
            sort(tmp.begin(), tmp.end());
            if(dict.find(tmp) != dict.end())
            {
                result.push_back(word);
                if(!duplicate.count(dict[tmp]))
                {
                    result.push_back(dict[tmp]);
                    duplicate.insert(dict[tmp]);
                }
            }
            else
            {
                dict[tmp] = word;
            }
            
            iter ++;
        }
        return result;
    }
};