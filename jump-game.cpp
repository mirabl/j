class Solution {
public:
    bool rec(vector<int>& A, int v, vector<bool>& reachable) {
         for (int w = min(int(A.size()) - 1, v + A[v]); w >= v; w--) {
            if (w == A.size() - 1) {
                return true;
            }
            if (!reachable[w]) {
                reachable[w] = true;
                if (rec(A, w, reachable)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool canJump2(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int n = nums.size();
        vector<bool> reachable(n, false);
        reachable[0] = true;
        return rec(nums, 0, reachable);
    }
    
    bool canJump3(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        queue<int> Q;
        vector<bool> reachable(nums.size(), false);
        Q.push(0);
        while (!Q.empty()) {
            cout << Q.size() << endl;
            int v = Q.front();
            if (v == nums.size() - 1) {
                return true;
            }
            Q.pop();
            if (!reachable[v]) {
                for (int i = v + 1; i <= min(int(nums.size()) - 1, v + nums[v]); i++) {
                    if (!reachable[i]) {
                        Q.push(i);
                    }
                }
            }
            reachable[v] = true;
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        vector<pair<int, int>> intervals;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            intervals.push_back({i, i + nums[i]});
        }
        sort(intervals.begin(), intervals.end());
        int right = 0;
        for (auto p: intervals) {
            if (p.first > right) {
                return false;
            } else {
                right = max(right, p.second);
            }
        }
        return true;
    }
    
};

    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int right = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > right) {
                return false;
            } else {
                right = max(right, i + nums[i]);
            }
        }
        return true;
    }

    bool canJump(vector<int>& nums) {
        int right = 0;
        for (int i = 0; i < nums.size() && i <= right; i++) {
            right = max(right, i + nums[i]);
        }
        return right >= nums.size() - 1;
    }    