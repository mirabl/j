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
    int f(int y, vector<pair<int, int>>& starts, int lo, int hi) {
        if (lo > hi) {
            return -1;
        }
        
        int mid = lo + (hi - lo) / 2;
        int ymid = starts[mid].first;
        if (ymid < y) {
            return f(y, starts, mid + 1, hi);
        } else if (mid == 0 || starts[mid - 1].first < y) {
            return starts[mid].second;
        } else {
            return f(y, starts, lo, mid - 1);
        }
    }
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<pair<int, int>> starts;
        for (int j = 0; j < int(intervals.size()); j++) {
            starts.push_back({intervals[j].start, j});
        }
        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for (auto i: intervals) {
            res.push_back(f(i.end, starts, 0, int(starts.size()) - 1));
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
    int fm(int target, vector<pair<int, int>>& A) {
        int lo = 0;
        int hi = int(A.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid].first < target) {
                lo = mid + 1;
            } else if (mid == 0 || A[mid - 1].first < target) {
                return A[mid].second;
            } else {
                hi = mid;
            }
        }
        
        return -1;
    }
    
    
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res;
        vector<pair<int, int>> starts;
        int N = intervals.size();
        for (int i = 0; i < N; i++) {
            starts.push_back({intervals[i].start, i});
        }
        sort(starts.begin(), starts.end());
        
        for (int i = 0; i < N; i++) {
            int f = fm(intervals[i].end, starts);
            res.push_back(f);
        }
        
        return res;
    }
};


class Solution {
public:
    int fm(vector<pair<int, int>>& starts, int end) {
        int best = -1;
        int lo = 0;
        int hi = int(starts.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (starts[mid].first >= end) {
                best = starts[mid].second;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return best;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(fm(starts, intervals[i][1]));
        }
        return res;
    }
};


class Solution {
public:
    int firstGreater(vector<pair<int, int>>& A, int x) {
        int best = -1;
        int lo = 0;
        int hi = int(A.size()) - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid].first >= x) {
                best = A[mid].second;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return best;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> starts;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(firstGreater(starts, intervals[i][1]));
        }
        return res;
    }
};


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starts;
        for (int i = 0; i < intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];
            if (starts.count(s) == 0) {
                starts[s] = i;
            }
        }
        
        vector<int> res;
        for (auto i: intervals) {
            auto it = starts.lower_bound(i[1]);
            if (it == starts.end()) {
                res.push_back(-1);
            } else {
                res.push_back((*it).second);
            }
        }
        return res;
    }
};
