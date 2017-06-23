class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m1 = -1;
        int M1 = -1;
        int m2 = -1;
        int M2 = -1;
        int n = arrays.size();
        for (int i = 0; i < n; i++) {
            if (arrays[i].empty()) {
                continue;
            }
            if (m1 == -1 || arrays[i][0] < arrays[m1][0]) {
                m2 = m1;
                m1 = i;
            } else if (m2 == -1 || arrays[i][0] < arrays[m2][0]) {
                m2 = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arrays[i].empty()) {
                continue;
            }
            if (M1 == -1 || arrays[i].back() > arrays[M1].back()) {
                M2 = M1;
                M1 = i;
            } else if (M2 == -1 || arrays[i].back() > arrays[M2].back()) {
                M2 = i;
            }
        }
        if (m1 != M1) {
            return arrays[M1].back() - arrays[m1][0];
        } else {
            return max(arrays[M1].back() - arrays[m2][0], arrays[M2].back() - arrays[m1][0]);
        }
    }
};

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m1 = -1;
        int M1 = -1;
        int m2 = -1;
        int M2 = -1;
        int d = 0;
        int n = arrays.size();
        for (int i = 0; i < n; i++) {
            if (arrays[i].empty()) {
                continue;
            }

            if (M1 != -1) {
                d = max(d, arrays[M1].back() - arrays[i][0]);
            }
            if (m1 != -1) {
                d = max(d, arrays[i].back() - arrays[m1][0]);
            }
            
            if (m1 == -1 || arrays[i][0] < arrays[m1][0]) {
                m1 = i;
            }
            if (M1 == -1 || arrays[i].back() > arrays[M1].back()) {
                M1 = i;
            }
        }
        return d;
    }
};



class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = 10000 + 1;
        int M = -10000 - 1;
        int d = 0;
        for (int i = 0; i < arrays.size(); i++) {
            if (!arrays[i].empty()) {
                d = max(d, M - arrays[i][0]);
                d = max(d, arrays[i].back() - m);
                m = min(m, arrays[i][0]);
                M = max(M, arrays[i].back());
            }
        }
        return d;
    }
};

