class RecentCounter {
public:
    int lasti = 0;
    vector<int> v;
    
    RecentCounter() {
    }
    
    int ping(int t) {
        v.push_back(t);
        while (v[lasti] < t - 3000) {
            lasti++;
        }
        return v.size() - lasti;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
