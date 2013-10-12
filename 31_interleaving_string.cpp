class Solution {
public:
	// do not pass the large scale test cases
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
    	if(s3.size() != s1.size() + s2.size()) return false;
		
		if(s1 == "") return s3 == s2;
		if(s2 == "") return s3 == s1;
		
		if(s3.at(0) == s1.at(0))
		{
			if(s3.at(0) != s2.at(0))
			{
				return isInterleave(s1.substr(1), s2, s3.substr(1));
			}
			else
			{
				return isInterleave(s1.substr(1), s2, s3.substr(1)) || isInterleave(s1, s2.substr(1), s3.substr(1));
			}
		}
		else if(s3.at(0) == s2.at(0))
		{
			return isInterleave(s1, s2.substr(1), s3.substr(1));
		}
		else
		{
			return false;
		}
    }
	
	//pass the large scale test case
	bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s3.size() != s1.size() + s2.size()) return false;
        
        int s1_size = s1.size();
        int s2_size = s2.size();
        
        bool interleaving_dp[s1_size + 1][s2_size + 1];
        //initialize
        for(int i = 1; i <= s1_size; ++ i)
        {
            if(s3.at(i - 1) == s1.at(i - 1)) interleaving_dp[i][0] = true;
            else interleaving_dp[i][0] = false;
        }
        
        for(int i = 1; i <= s2_size; ++ i)
        {
            if(s3.at(i - 1) == s2.at(i - 1)) interleaving_dp[0][i] = true;
            else interleaving_dp[0][i] = false;
        }
        
        for(int i = 1; i <= s1_size; ++ i)
        {
            for(int j = 1; j <= s2_size; ++ j)
            {
                interleaving_dp[i][j] = false;
                if(s3.at(i + j - 1) == s1.at(i - 1)) interleaving_dp[i][j] |= interleaving_dp[i - 1][j];
                if(s3.at(i + j - 1) == s2.at(j - 1)) interleaving_dp[i][j] |= interleaving_dp[i][j - 1];
            }
        }
        
        return interleaving_dp[s1_size][s2_size];
    }
};