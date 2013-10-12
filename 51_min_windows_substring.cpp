class Solution {
    #include <map>
    #include <deque>
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(S.size() < T.size()) return "";
        
        map<char, deque<int> > hash;
        map<char, deque<int> >::iterator iter;
        //build a hash map
        for(int i = 0; i < T.size(); ++ i)
        {
            iter = hash.find(T.at(i));
            if(iter == hash.end())
            {
                deque<int> tmp;
                hash[T.at(i)] = tmp;
            }
            
            hash[T.at(i)].push_back(-1);
        }
        
        int min_window = S.size() + 1, min_index = -1, count = 0;
        for(int i = 0; i < S.size(); ++ i)
        {
            iter = hash.find(S.at(i));
            if(iter != hash.end())
            {
                deque<int> &finder = iter->second;
                deque<int>::iterator diter = find(finder.begin(), finder.end(), -1);
                
                if(diter != finder.end())
                {
                    ++ count;
                    *diter = i;
                }
                else
                {
                    finder.pop_front();
                    finder.push_back(i);
                }

                if(count == T.size())
                {
                    int tmp = S.size();
                    for(map<char, deque<int> >::iterator tmp_iter = hash.begin(); tmp_iter != hash.end(); ++ tmp_iter)
                    {
                        if((tmp_iter->second)[0] < tmp) tmp = (tmp_iter->second)[0];
                    }
                    
                    if(i - tmp + 1 < min_window)
                    {
                        min_index = tmp;
                        min_window = i - tmp + 1;
                    }
                }
            }
        }
        
        if(min_index == -1) return "";
        return S.substr(min_index, min_window);
    }
};