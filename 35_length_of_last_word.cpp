class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sentence_len = strlen(s);
        const char *index = s + sentence_len - 1;
        int count = 0;
        
        while(*index == ' ') --index;
        while(index >= s && *index != ' ')
        {
            count ++;
            index --;
        }
        
        return count;
    }
};