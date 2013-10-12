class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int index = 0;
        int count = 0;
        
        while(index < n - 1)
        {
            count ++;
            int max_len = index + A[index];
            int max_index = max_len;
            if(max_index >= n - 1) break;
            
            for(int i = index + 1; i < max_len; ++ i)
            {
                if(A[i] + i > max_index + A[max_index])
                {
                    max_index = i;
                }
            }
            index = max_index;
        }
        return count;
    }
};