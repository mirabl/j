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