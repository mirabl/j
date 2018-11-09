class Solution {
public:
    vector<pair<int, int>> res;
    vector<int> maxH;
    vector<int> X;

    
    void updateMax(int start, int end, int height) {
       for (int i = 0; i < X.size(); i++) {
            if (X[i] >= start && X[i] < end) {
                maxH[i] = max(maxH[i], height);
            }
        }
    }
    
    int getMax(int i) {
        return maxH[i];
    }
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) {
            return {};
        }
        
        int cheight = 0;
        for (auto building: buildings) {
            int start = building[0];
            int end = building[1];
            int height = building[2];
            X.push_back(start); // not the end?
            X.push_back(end);
        }
        
        sort(X.begin(), X.end());
        
        maxH = vector<int>(X.size());
        
        for (auto building: buildings) {
            int start = building[0];
            int end = building[1];
            int height = building[2];

            updateMax(start, end, height);
        }
        
        X.push_back(0);
        maxH.push_back(0);
        
        for (int i = 0; i < X.size(); i++) {
            if (i == 0 || getMax(i) != getMax(i - 1)) {
                res.push_back({X[i], getMax(i)});
            }
        }
        
        return res;
    }
};

// possible: segment tree
