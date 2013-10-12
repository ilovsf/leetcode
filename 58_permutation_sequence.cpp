class Solution {
public:
    void getNextPermutation(vector<int> &seq){
        int size = seq.size();
        
        int first_index = size - 2;
        while(first_index >= 0 && seq[first_index] >= seq[first_index + 1]) -- first_index;
        
        if(first_index >= 0)
        {
            int second_index = size - 1;
            while(second_index >= 0 && seq[second_index] <= seq[first_index]) -- second_index;
            if(second_index >= 0)
            {
                swap(seq[first_index], seq[second_index]);
                reverse(seq.begin() + first_index + 1, seq.end());
            }
        }
        else
        {
            reverse(seq.begin(), seq.end());
        }
    }

    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> seq;
        
        for(int i = 1; i <= n; ++ i)
        {
            seq.push_back(i);
        }
        
        for(int i = 1; i < k; ++ i)
        {
            getNextPermutation(seq);
        }
        
        stringstream oss;
        for(int i = 0; i < n; ++ i)
        {
            oss << seq[i];
        }
        
        return oss.str();
    }
};