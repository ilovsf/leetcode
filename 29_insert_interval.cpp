/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        
        int index = 0, interval_size = intervals.size();
        while(index < interval_size - 1)
        {
            Interval tmp(intervals[index].start, intervals[index].end);
            int tmp_index = index + 1;
            
            while(tmp_index < interval_size && intervals[tmp_index].start <= tmp.end)
            {
                if(intervals[tmp_index].end > tmp.end) tmp.end = intervals[tmp_index].end;
                tmp_index ++;
            }
            
            result.push_back(tmp);
            index = tmp_index;
        }
        
        if(index == interval_size - 1) result.push_back(intervals[index]);
        
        return result;
    }
};