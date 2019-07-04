class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> A(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    A[i] = max(A[i], A[j] + 1);
                }
            }
        }
        return *max_element(A.begin(), A.end());
    }
};

class Solution {
public:
    const int kNotFound = -1;
    
    int firstGreater(vector<int>& T, int x) {
        int lo = 0;
        int hi = int(T.size()) - 1;
        int best = kNotFound;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (T[mid] >= x) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return best;
    }
    
    int lengthOfLIS(vector<int>& A) {
        vector<int> T;
        for (auto x: A) {
            int i = firstGreater(T, x);
            if (i == kNotFound) {
                T.push_back(x);
            } else {
                T[i] = x;
            }
        }
        return T.size();
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        
        int n = A.size();
        vector<int> T(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (A[i] > A[j]) {
                    T[i] = max(T[i], 1 + T[j]);
                }
            }
        }
        return *max_element(T.begin(), T.end());
    }
};


// n2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> T;
        for (int x: nums) {
            int i = 0;
            while (i < T.size()) {
                if (T[i] >= x) {
                    T[i] = x;
                    break;
                }
                i++;
            }
            if (i == T.size()) {
                T.push_back(x);
            }
        }
        return T.size();
    }
};

class Solution {
public:
    int firstLargerOrEqual(vector<int>& T, int x) {
        int best = -1;
        int lo = 0;
        int hi = int(T.size()) - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (T[mid] >= x) {
                best = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            } 
        }
        return best;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> T;
        for (int x: nums) {
            int i = firstLargerOrEqual(T, x);
            if (i == -1) {
                T.push_back(x);
            } else {
                T[i] = x;
            }
        }
        return T.size();
    }
};
