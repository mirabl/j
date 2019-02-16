class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> S;
        for (int i = 0; pow(x, i) <= bound; i++) {
            for (int j = 0; pow(x, i) + pow(y, j) <= bound; j++) {
                S.insert(pow(x, i) + pow(y, j));
                if (y == 1) {
                    break;
                }
            }
            if (x == 1) {
                break;
            }
        }
        
        vector<int> v(S.begin(), S.end());
        return v;
    }
};
