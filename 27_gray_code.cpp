class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int size = 1 << n;
        for(int i = 0; i < size; ++ i)
        {
            int gray = (i >> 1) ^ i;
            result.push_back(gray);
        }
        
        return result;
    }
};