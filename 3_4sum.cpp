class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> tmp(4);
        int array_size = num.size();
        
        sort(num.begin(), num.end());
        for(int i = 0; i < array_size - 1; ++ i)
        {
            // avoid duplicate
            if(i > 0 && num[i - 1] == num[i]) continue;
            int first = num[i];
            
            for(int j = i + 1; j < array_size; ++ j)
            {
                // avoid duplicate too
                if(j > i + 1 && num[j - 1] == num[j]) continue;
                
                int second = num[j];
                int begin = j + 1;
                int end = array_size - 1;
                int left_sum = target - first - second;
                while(begin < end)
                {
                    //narrow the border
                    while(begin < end - 1 && num[begin + 1] == num[begin]) begin ++;
                    while(begin < end - 1 && num[end - 1] == num[end]) end --;
                    
                    int tmp_sum = num[begin] + num[end];
                    if(tmp_sum < left_sum)
                    {
                        begin ++;
                    }
                    else if(tmp_sum > left_sum)
                    {
                        end --;
                    }
                    else
                    {
                        tmp[0] = first;
                        tmp[1] = second;
                        tmp[2] = num[begin ++];
                        tmp[3] = num[end --];
                        result.push_back(tmp);
                    }
                }
            }
        }
        
        return result;
    }
};