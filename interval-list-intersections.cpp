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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int i1 = 0;
        int i2 = 0;
        int n1 = A.size();
        int n2 = B.size();
        vector<Interval> res;
        while (i1 < n1 && i2 < n2) {
            auto a = A[i1];
            auto b = B[i2];
            if (b.end < a.start) {
                i2++;
            } else if (a.end < b.start) {
                i1++;
            } else {
                int start = max(a.start, b.start);
                int end = min(a.end, b.end);
                res.push_back(Interval(start, end));
                if (a.end <= b.end) {
                    i1++;
                } else {
                    i2++;
                }
            }
            
        }
        
        return res;
    }
};
