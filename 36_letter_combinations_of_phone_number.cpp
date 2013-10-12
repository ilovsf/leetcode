class Solution {
public:
    void gen_all_perm(string digits, int index, vector<string>& dict, string curr_res, vector<string> &res)
    {
        if(index >= digits.size())
        {
            res.push_back(curr_res);
        }
        else
        {
            int digit = digits[index] - '0';
            string sub_dict = dict[digit];
            for(int i = 0; i < sub_dict.size(); ++ i)
            {
                curr_res.insert(curr_res.end(), sub_dict.at(i));
                gen_all_perm(digits, index + 1, dict, curr_res, res);
                curr_res.erase(curr_res.end() - 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // build a dictionary for 0~9
        vector<string> digit_hash;
        digit_hash.push_back(" ");
        digit_hash.push_back("1");
        digit_hash.push_back("abc");
        digit_hash.push_back("def");
        digit_hash.push_back("ghi");
        digit_hash.push_back("jkl");
        digit_hash.push_back("mno");
        digit_hash.push_back("pqrs");
        digit_hash.push_back("tuv");
        digit_hash.push_back("wxyz");
        
        vector<string> result;
        string tmp;
        
        if(digits.size() == 0)
        {
            result.push_back("");
            return result;
        }
        
        gen_all_perm(digits, 0, digit_hash, tmp, result);
        
        return result;
    }
};