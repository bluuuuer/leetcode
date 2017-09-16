/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }
        
        sort(intervals.begin(), intervals.end(), MyComp);
        
        result.push_back(intervals[0]);
        int i = 0;
        for (int j = 1; j < intervals.size(); j ++) {
            if (result[i].end >= intervals[j].start) {
                result[i].end = max(result[i].end, intervals[j].end);
            } else {
                result.push_back(intervals[j]);
                i ++;
            }
        }
        return result;
    }
private:
    static bool MyComp(Interval first, Interval last) {
        return first.start < last.start;
    }
};
