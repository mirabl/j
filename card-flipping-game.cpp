
// contest
class Solution {
public:
    bool check(int v, vector<int>& fronts, vector<int>& backs) {
        for (int i = 0; i < fronts.size(); i++) {
            if (fronts[i] == v && backs[i] == v) {
                return false;
            }
        }
        return true;
    }

    
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int best = 2001;
        for (int i = 0; i < fronts.size(); i++) {
            if (check(fronts[i], fronts, backs)) {
                best = min(best, fronts[i]);
            }
            if (check(backs[i], fronts, backs)) {
                best = min(best, backs[i]);
            }
        }
        return best == 2001 ? 0 : best;
    }
};

