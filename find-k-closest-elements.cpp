class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> V;
        for (auto y: arr) {
            V.push_back({abs(x - y), y});
        }
        sort(V.begin(), V.end());
        
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(V[i].second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0;
        int hi = int(arr.size()) - 1;
        
        while (hi - lo + 1 > k) {
            if (abs(arr[hi] - x) < abs(arr[lo] - x)) {
                lo++;
            } else {
                hi--;
            }
        }
        
        vector<int> res(arr.begin() + lo, arr.begin() + hi + 1);
        return res;
    }
};
