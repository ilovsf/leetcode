class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int> > result;
		vector<int> tmp(3);

		sort(num.begin(), num.end());
		for(int i = 0; i < num.size(); i ++)
		{
			if(i > 0 && num[i - 1] == num[i]) continue;
			int first = num[i];
			int left_sum = 0 - first;
			int begin = i + 1;
			int end = num.size() - 1;
			while(begin < end)
			{
				while(begin < end - 1 && num[end - 1] == num[end]) {end --;}
				while(begin < end - 1 && num[begin + 1] == num[begin]) {begin ++;}
				if (num[begin] + num[end] > left_sum)
				{
					end --;
				}
				else if(num[begin] + num[end] < left_sum)
				{
					begin ++;
				}
				else
				{
					tmp[0] = first;
					tmp[1] = num[begin ++];
					tmp[2] = num[end --];
					result.push_back(tmp);
				}
			}
		}
		return result;
	}
};