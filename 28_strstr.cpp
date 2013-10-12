class Solution {
public:
    void get_next(const char *needle, int *next)
	{
		//initialize the next array
		next[0] = -1;
		
		int sub = -1, main = 0;
		while(needle[main + 1] != '\0')
		{
			if(sub == -1 || needle[main] == needle[sub])
			{
				++ sub; 
				++ main;
				if(needle[main] == needle[sub]) next[main] = next[sub];
				else next[main] = sub;
			}
			else
			{
				sub = next[sub];
			}
		}
	}
	
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(haystack == NULL || needle == NULL) return NULL;
		
		int needle_len = strlen(needle);	
		int haystack_len = strlen(haystack);
		int *next = new int[needle_len];
		
		// generate next array
		get_next(needle, next);
		
		int pos_haystack = 0, pos_needle = 0;
		while(pos_haystack < haystack_len && pos_needle < needle_len)
		{
			if(pos_needle == -1 || haystack[pos_haystack] == needle[pos_needle]) 
			{
				++ pos_haystack;
				++ pos_needle;
			}
			else
			{
				pos_needle = next[pos_needle];
			}
		}
		
		if(pos_needle == needle_len) return haystack + pos_haystack - needle_len;
		else return NULL;
    }
};