class Solution {
public:
    int findKth(int *A, int lenA, int *B, int lenB, int k)
    {
        //always keep A as a shorter array
        if(lenA > lenB) return findKth(B, lenB, A, lenA, k);
        
        //recursion end
        if(lenA == 0) return B[k - 1];
        if(k == 1) return min(*A, *B);
        
        //allocate k/2 to A and B
        int pa = min(k/2, lenA);
        int pb = k - pa;
        
        if(*(A + pa - 1) < *(B + pb - 1))
        {
            return findKth(A + pa, lenA - pa, B, lenB, k - pa);
        }
        
        return findKth(A, lenA, B + pb, lenB - pb, k - pb);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int total_num = m + n;
        if(total_num % 2 == 0)
        {
            return ((double)findKth(A, m, B, n, total_num / 2) 
                    + (double)findKth(A, m, B, n, total_num / 2 + 1)) / 2;
        }
        
        return findKth(A, m, B, n, total_num / 2 + 1);
    }
};