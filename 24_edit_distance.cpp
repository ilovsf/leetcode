class Solution {
public:
    int min_three(int num1, int num2, int num3)
    {
        int smaller = num1 < num2 ? num1 : num2;
        
        return smaller < num3 ? smaller : num3;
    }

	// can't pass the large data test
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(word1.size() == 0 && word2.size() == 0)
            return 0;
        if(word1.size() == 0)
            return word2.size();
        if(word2.size() == 0)
            return word1.size();
        
        if(word1[0] == word2[0])
            return minDistance(word1.substr(1), word2.substr(1));
        else
        {
            //delete from word2
            int num1 = minDistance(word1, word2.substr(1));
            //change a single char
            int num2 = minDistance(word1.substr(1), word2.substr(1));
            //delete from word1
            int num3 = minDistance(word1.substr(1), word2);
            
            return 1 + min_three(num1, num2, num3);
        }
    }
	
	int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // c[i][j] means word1.substr(0, i) and word2.substr(0, j)'s min distance
        int word1_length = word1.size();
        int word2_length = word2.size();
        
        if(word1_length == 0)
            return word2_length;
        if(word2_length == 0)
            return word1_length;
        
        int c[word1_length + 1][word2_length + 1];
        int min_dist = word1_length > word2_length ? word1_length + 1 : word2_length + 1;
        
        //initialize the border, i.e. the edit distance of empty string 
        //and word whose length is x
        for(int i = 0; i < word1_length + 1; ++ i)
        {
            c[i][0] = i;
        }
        
        for(int j = 0; j < word2_length + 1; ++ j)
        {
            c[0][j] = j;
        }
        
        for(int i = 1; i < word1_length + 1; ++ i)
        {
            for(int j = 1; j < word2_length + 1; ++ j)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    c[i][j] = c[i - 1][j - 1];
                }
                else
                {
                    int num1 = c[i - 1][j];
                    int num2 = c[i - 1][j - 1];
                    int num3 = c[i][j - 1];
                    
                    c[i][j] = min_three(num1, num2, num3) + 1;
                }
            }
        }
        
        return c[word1_length][word2_length];
    }
};