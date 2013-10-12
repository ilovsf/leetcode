class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function        
        string a = "1";
        int counter = 1;
        
        while(counter < n)
        {
            string previous = a;
            string b;
            for(int index = 0; index < previous.size();)
            {
                // look for more same integers
                int j = index;
                while(j + 1 < previous.size() && previous[j + 1] == previous[j]) ++ j;
                
                char duplicate_num = j - index + 1 + '0';
                b.insert(b.end(), duplicate_num);
                b.insert(b.end(), previous[j]);
                
                index = j + 1;
            }
            a = b;
            counter ++;
        }
        
        return a;
    }
};