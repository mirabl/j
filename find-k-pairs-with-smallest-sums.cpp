class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, pair<int, int>>> Q;
        set<pair<int, int>> seen;

        if (!A.empty() && !B.empty()) {
            Q.push({- (A[0] + B[0]), {0, 0}});
            seen.insert({0, 0});
        }
        while (k > 0 && !Q.empty()) {
            auto p = Q.top().second;
            Q.pop();
            res.push_back({A[p.first], B[p.second]});
            for (int i = 0; i < 2; i++) {
                int x = p.first + 1 - i;
                int y = p.second + i;
                if (seen.count({x, y}) == 0 && x < A.size() && y < B.size()) {
                    Q.push({- (A[x] + B[y]), {x, y}});
                    seen.insert({x, y});
                }
            }
            k--;
        }
        return res;
    }
};

// could avoid using a set:
// https://discuss.leetcode.com/topic/50481/clean-16ms-c-o-n-space-o-klogn-time-solution-using-priority-queue

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }
        priority_queue<pair<int, pair<int, int>>> Q; // or use special comparator
        for (int j = 0; j < nums2.size(); j++) {
            Q.push({- (nums1[0] + nums2[j]), {0, j}});
        }
        vector<pair<int, int>> res;
        while (k > 0 && !Q.empty()) {
            auto p = Q.top();
            int x = p.second.first;
            int y = p.second.second;
            Q.pop();
            res.push_back({nums1[x], nums2[y]});
            if (x + 1 < nums1.size()) {
                Q.push({- (nums1[x + 1] + nums2[y]), {x + 1, y}});
            }
            k--;
        }
        return res;
    }
};