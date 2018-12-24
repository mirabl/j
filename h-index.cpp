class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) {
            return 0;
        }
        sort(citations.begin(), citations.end());
        int hmax = -1;
        const int N = int(citations.size());
        for (int h = 0; h <= N; h++) {
            if ((h == 0 || citations[N - h] >= h) && (N - h == 0 || citations[N - h - 1] <= h)) {
                hmax = max(hmax, h);
            }
        }
        return hmax;
    }
};