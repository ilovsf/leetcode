class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int closest_num = 1 << 31 - 1;
        int result;
        int array_size = num.size();
        
        if(array_size < 3)
        {
            //error handler
            return -1;   
        }
        
        sort(num.begin(), num.end());
        for(int i = 0; i < array_size; ++ i)
        {
            int first = num[i];
            int left_sum = target - first;
            int begin = i + 1;
            int end = array_size - 1;
            
            while(begin < end)
            {
                int tmp_sum = num[begin] + num[end];
                
                if(tmp_sum < left_sum)
                {
                    if(left_sum - tmp_sum < closest_num)
                    {
                        closest_num = left_sum - tmp_sum;
                        result = tmp_sum + first;
                    }
                    begin ++;
                }
                else if(tmp_sum > left_sum)
                {
                    if(tmp_sum - left_sum < closest_num)
                    {
                        closest_num = tmp_sum - left_sum;
                        result = tmp_sum + first;
                    }
                    end --;
                }
                else
                {
                    return tmp_sum + first;
                }
            }
        }
        
        return result;
    }
};