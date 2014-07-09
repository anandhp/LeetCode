/**
    Given a collection of intervals, merge all overlapping intervals.
    
    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].
    

    Definition for an interval.
   
    struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
    };

**/
class Solution {
public:
    static bool overlap(const Interval& begin, const Interval& end) {
       return begin.start < end.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        
        if (intervals.size() == 0)
            return result;
        
        std::sort(intervals.begin(), intervals.end(), Solution::overlap);
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end >= intervals[i].start) {
                result.back().end = std::max(result.back().end, intervals[i].end);
            } else {
                result.push_back(intervals[i]);
            }
        }
        
        return result;
    }
};