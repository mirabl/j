class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int from = -1;
        for (int x: timeSeries) {
            if (from != -1) {
                res += min(duration, x - from);
            }
            from = x;
        }
        return (from == -1 ? 0 : res + duration);
    }
};