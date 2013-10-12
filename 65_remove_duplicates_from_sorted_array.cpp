class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return 0;
        
        int update_index = 0;
        int index = 0;
        while(index < n)
        {
            int next_index = index + 1;
            while(next_index < n && A[next_index - 1] == A[next_index]) next_index ++;
            
            A[update_index ++] = A[index];
            index = next_index;
        }
        
        return update_index;
    }
};