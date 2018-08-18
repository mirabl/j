class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        sort(hand.begin(), hand.end());
        map<int, int> F;
        for (auto x: hand) {
            F[x]++;
        }
        for (auto x: hand) {
            if (F[x] > 0) {
                int y = x;
                for (int y = x; y < x + W; y++) {
                    if (F[y] == 0) {
                        return false;
                    }
                    F[y]--;
                }
            }
        }
        return true;
    }
};
