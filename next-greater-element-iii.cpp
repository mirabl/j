class Solution {
public:
    int complete(int n, vector<int>& D, vector<bool>& used, int p, int remain) {
        if (remain == 0) {
            return p;
        }
        int b = 1;
        for (int i = 0; i < remain - 1; i++) {
            b *= 10;
        }
        int max_val = 0x7fffffff;
        for (int i = 0;  i < D.size(); i++) {
            if (!used[i]) {
                int q = p + b * D[i];
                if (q < max_val) {
                    used[i] = true;
                    int r = complete(n, D, used, q, remain - 1);
                    if (r > n) {
                        return r;
                    }
                    used[i] = false;
                }
            }
        }
        return -1;
    }

    int nextGreaterElement(int n) {
        vector<int> D;
        int m = n;
        do {
            D.push_back(m % 10);
            m /= 10;
        } while (m != 0);
        sort(D.begin(), D.end());
        int remain = D.size();
        vector<bool> used(remain, false);
        
        return complete(n, D, used, 0, remain);
    }
};

class Solution {
public:
    int complete(int n, vector<int>& D, int p, int remain) {
        if (remain == 0) {
            return p;
        }
        int b = 1;
        for (int i = 0; i < remain - 1; i++) {
            b *= 10;
        }
        int max_val = 0x7fffffff;
        for (int i = 0;  i < 10; i++) {
            int q = p + b * i;
            if (D[i] > 0 && q < max_val) {
                D[i]--;
                int r = complete(n, D, q, remain - 1);
                if (r > n) {
                    return r;
                }
                D[i]++;
            }
        }
        return -1;
    }

    int nextGreaterElement(int n) {
        vector<int> D(10, 0);
        int m = n;
        int digits = 0;
        do {
            D[m % 10]++;
            m /= 10;
            digits++;
        } while (m != 0);
        return complete(n, D, 0, digits);
    }
};

// Better: use next_permutation (lexicographic)