class Solution {
public:
    void dfsPermute(int index, int N, vector<int> &num, vector<vector<int> > &res){
        if(index == N)
        {
            res.push_back(num);
        }
        else
        {
            for(int i = index; i < N; ++ i)
            {
                swap(num[index], num[i]);
                dfsPermute(index + 1, N, num, res);
                swap(num[index], num[i]);
            }
        }
    }
    
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(num.size() == 0) return result;
        
        int size = num.size();
        dfsPermute(0, size, num, result);
        
        return result;
    }
};