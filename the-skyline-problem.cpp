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


class Solution {
public:
    vector<vector<int>> s(vector<vector<int>>& B, int lo, int hi) {
        cout << "s: lo=" << lo << ", hi=" << hi << endl;
        if (lo > hi) {
            return {};
        } else if (lo == hi) {
            return {{B[lo][0], B[lo][2]}, {B[lo][1], 0}};
        }
        
        int mid = lo + (hi - lo) / 2;
        auto sA = s(B, lo, mid);
        auto sB = s(B, mid + 1, hi);
        return merge(sA, sB);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& A, vector<vector<int>>& B) {
        cout << "merge " << A.size() << " " << B.size() << endl;
        vector<vector<int>> C;
        int n = A.size();
        int m = B.size();
        int i = 0;
        int j = 0;
        int h = 0;
        
        vector<int> points;
        
        while (i < n && j < m) {
            if (A[i][0] < B[j][0]) {
                points.push_back(A[i][0]);
                i++;
            } else if (A[i][0] > B[j][0]) {
                points.push_back(B[j][0]);
                j++;
            } else {
                points.push_back(A[i][0]);
                i++;
                j++;
            }
        }
        
        while (i < n) {
            points.push_back(A[i][0]);
            i++;
        }
        while (j < m) {
            points.push_back(B[j][0]);
            j++;
        }
        
        int L = points.size();
        vector<int> M(L, 0);
        int infty = 1e6;
        A.push_back({infty, 0});
        for (int k = 0, i = 0; i < n; i++) {
            while (k < L && points[k] < A[i][0]) {
                k++;
            }
            while (k < L && points[k] < A[i + 1][0]) {
                M[k] = max(M[k], A[i][1]);
                k++;
            }
        }
           
        B.push_back({infty, 0});
        for (int k = 0, j = 0; j < m; j++) {
            while (k < L && points[k] < B[j][0]) {
                k++;
            }
            while (k < L && points[k] < B[j + 1][0]) {
                M[k] = max(M[k], B[j][1]);
                k++;
            }
        }
        
        for (int i = 0; i < L; i++) {
            if (i > 0 && M[i] == M[i - 1]) {
                continue;
            }
            C.push_back({points[i], M[i]});
        }
        
        return C;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return s(buildings, 0, int(buildings.size()) - 1);
    }
};
