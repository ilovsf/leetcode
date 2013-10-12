/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &a, const Interval &b)
{
    return a.start < b.start;    
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
		
		int interval_size = intervals.size();
		if(interval_size == 0) return result;
		
		sort(intervals.begin(), intervals.end(), compare);
		int index = 0;
		while(index < interval_size)
		{
			Interval interval;
			interval.start = intervals[index].start;
			interval.end = intervals[index].end;
            
			int tmp_index = index + 1;
			while(tmp_index < interval_size && intervals[tmp_index].start <= interval.end)
			{
                interval.end = max(intervals[tmp_index].end, interval.end);
				++ tmp_index;
			}
			
			result.push_back(interval);
			index = tmp_index;
		}
		
		return result;
    }
};