class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s == "") return 0;
        
        int str_size = s.size();
    	int *pos_dict = new int[256];
		int *opt = new int[str_size];
		
		memset(pos_dict, -1, sizeof(int) * 256);
		int max = 1;
		opt[0] = 1;
        pos_dict[s.at(0)] = 0;
        
		for(int i = 1; i < str_size; ++ i)
		{
			char ch = s.at(i);
			if(pos_dict[ch] == -1)
			{
				opt[i] = opt[i - 1] + 1;
			}
			else
			{
				int index = pos_dict[ch];
				opt[i] = i - index;
				for(int j = 0; j < 256; ++ j)
                {
                    if(pos_dict[j] < index) pos_dict[j] = -1;
                }
			}
            pos_dict[ch] = i;
            
			if(opt[i] > max) max = opt[i];
		}
		
		return max;
    }
};