class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(S.size() == 0) 
        {
            res.push_back(vector<int>());
            return res;
        }
        
        set<vector<int> > dict;
        
        sort(S.begin(), S.end());
        int size = 1 << S.size();
        for(int i = 0; i < size; ++ i)
        {
            int count = 0;
            int dup = i;
            vector<int> unit;
            
            while(count < S.size())
            {
                if(dup & 0x1 == 1)
                {
                    unit.push_back(S[count]);
                }
                dup >>= 1;
                ++ count;
            }
            dict.insert(unit);
        }
        
        set<vector<int> >::iterator iter = dict.begin();
        for(;iter != dict.end(); ++ iter)
        {
            res.push_back(*iter);
        }
        
        return res;
    }
};