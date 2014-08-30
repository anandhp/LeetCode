/**
*   Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
*   
*   You may assume that the intervals were initially sorted according to their start times.
*   
*   Example 1:
*   Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
*   
*   Example 2:
*   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
*   
*   This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*
**/


class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i = 0, start = 0, end = 0;
        vector<Interval> newIntervals;
        
        if (intervals.size () == 0) {
            newIntervals.push_back(newInterval);
            return newIntervals; 
        }
        
        for (i = 0; i < intervals.size(); i++) {
            if (intervals[i].start > newInterval.start) {
                intervals.insert(intervals.begin() + i, newInterval);
                break;
            }
        }
        
        if (i == intervals.size())
            intervals.push_back(newInterval);
        
        newIntervals.push_back(intervals[0]);
        
        for (i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= newIntervals.back().end)
                newIntervals.back().end = max(newIntervals.back().end, intervals[i].end);
            else
                newIntervals.push_back(intervals[i]);
        }
        
        return newIntervals;
    }
};