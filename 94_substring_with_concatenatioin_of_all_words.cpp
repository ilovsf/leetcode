class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        
        if(L.size() == 0) return result;
        
        map<string, int> word_dict;
        int dict_size = L.size();
        int word_size = L[0].size();             
        int sentence_size = S.size();
        
        if(dict_size * word_size > sentence_size) return result;

        
        for(int i = 0; i < dict_size; ++ i)
        {
            ++ word_dict[L[i]];
        }
        
        for(int i = 0; i <= sentence_size - dict_size * word_size; ++ i)
        {
            //traverse all possible index
            map<string, int> tmp_dict;
            int j;
            for(j = 0; j < dict_size; ++ j)
            {
                // for every word
                string curr_word = S.substr(i + j * word_size, word_size);
                
                if(word_dict.find(curr_word) == word_dict.end()) break;
                else ++ tmp_dict[curr_word];
                
                if(tmp_dict[curr_word] > word_dict[curr_word]) break;
            }
            if(j == dict_size) result.push_back(i);
        }
        
        return result;
    }
};