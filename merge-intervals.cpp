/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval& a, const Interval& b) {
    return a.start < b.start;
}
    
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end(), comp);
        int start = intervals[0].start;
        int end = intervals[0].end;
        vector<Interval> res;
        for (Interval i: intervals) {
            if (i.start <= end) {
                end = max(end, i.end);
            } else {
                res.push_back(Interval(start, end));
                start = i.start;
                end = i.end;
            }
        }
        res.push_back(Interval(start, end));
        return res;
    }
};
