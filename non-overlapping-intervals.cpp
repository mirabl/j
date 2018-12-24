/*
https://leetcode.com/problems/non-overlapping-intervals/
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
bool comp(Interval a, Interval b) {
    return a.start < b.start;
}
 
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int cnt_non_overlap = 1;
        int end_last_good_interval = intervals[0].end;
        for (int i = 1; i < int(intervals.size()); ++i) {
            if (intervals[i].start < end_last_good_interval) {
                end_last_good_interval = min(end_last_good_interval, intervals[i].end);
            } else {
                cnt_non_overlap++;
                end_last_good_interval = intervals[i].end;
            }
        }
        return int(intervals.size()) - cnt_non_overlap;
    }
};