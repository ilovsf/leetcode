class Solution {
public:
    void dfsGenerateParens(int left, int right, string &curr_res, vector<string> &res)
    {
        if(left < 0 || right < left) return;
        
        else if(left == 0 && right == 0)
        {
            res.push_back(curr_res);
        }
        else
        {
            if(left > 0)
            {
                curr_res.insert(curr_res.end(), '(');
                dfsGenerateParens(left - 1, right, curr_res, res);
                curr_res.erase(curr_res.end() - 1);
            }
            
            if(right > left)
            {
                curr_res.insert(curr_res.end(), ')');
                dfsGenerateParens(left, right - 1, curr_res, res);
                curr_res.erase(curr_res.end() - 1);                
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        if(n == 0) return result;
        
        string curr_res;
        dfsGenerateParens(n, n, curr_res, result);
        
        return result;
    }
};