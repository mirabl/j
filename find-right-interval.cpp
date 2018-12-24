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
    vector<pair<int, int>> starts;
    int N;
    
    int fn(int x) {
        int lo = 0;
        int hi = N - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int y = starts[mid].first;
            
            if ((mid == 0 || starts[mid - 1].first < x) && starts[mid].first >= x) {
                return starts[mid].second;
            }
            
            if (starts[mid].first >= x) {
                hi = mid - 1;   
            } else {
                lo = mid + 1;
            }
        }
        return -1;            
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        N = intervals.size();
        for (int i = 0; i < N; i++) {
            starts.push_back({intervals[i].start, i});
        }
        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for (auto interval: intervals) {
            int i = fn(interval.end);
            res.push_back(i);
        }
        return res;
    }
};


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
    int fg(int x, vector<pair<int, int>>& starts, int lo, int hi) {
        if (x > starts[hi].first) {
            return -1;
        }
        int mid = lo + (hi - lo) / 2;
        if (starts[mid].first >= x && (mid == 0 || starts[mid - 1].first < x)) {
            return starts[mid].second;
        } else if (starts[mid].first >= x) {
            return fg(x, starts, lo, mid - 1);
        } else {
            return fg(x, starts, mid + 1, hi);
        }
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int>> starts;
        int N = intervals.size();
        for (int i = 0; i < N; i++) {
            starts.push_back({intervals[i].start, i});
        }
        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for (auto i: intervals) {
            res.push_back(fg(i.end, starts, 0, N - 1));
        }
        
        return res;
    }
};
