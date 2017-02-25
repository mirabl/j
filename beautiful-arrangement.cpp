class Solution {
public:
    void rec(int N, int position, set<int>& remain, int *res) {
        if (remain.empty()) {
            (*res)++;
        } else {
            for (int x: remain) {
                if (x % position == 0 || position % x == 0) {
                    remain.erase(x);
                    rec(N, position + 1, remain, res);
                    remain.insert(x);
                }
            }
        }
    }

    int countArrangement(int N) {
        set<int> remain;
        for (int i = 1; i <= N; i++) {
            remain.insert(i);
        }
        int res = 0;
        rec(N, 1, remain, &res);
        return res;
    }
};

