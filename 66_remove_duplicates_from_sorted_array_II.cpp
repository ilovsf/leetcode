class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        
        int index = 0, update_index = 0;
        
        while(index < n)
        {
            int tmp_index = index + 1;
            while(tmp_index < n && A[tmp_index - 1] == A[tmp_index]) ++ tmp_index;
            
            int len = min(tmp_index - index, 2);
            for(int i = 0; i < len; ++ i)
            {
                A[update_index ++] = A[index];
            }
            
            index = tmp_index;
        }
        
        return update_index;
    }
};