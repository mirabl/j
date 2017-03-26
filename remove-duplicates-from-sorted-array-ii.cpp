class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int lo = 0;
        int hi = 0;
        while (hi < A.size()) {
            if (hi <= 1 || A[hi] != A[lo - 1] || A[hi] != A[lo - 2]) {
                A[lo] = A[hi];
                lo++;
            }
            hi++;
        }
        return lo;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int lo = 0;
        for (int x: A) {
            if (lo <= 1 || x != A[lo - 1] || x != A[lo - 2]) {
                A[lo] = x;
                lo++;
            }
        }
        return lo;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& A) {
        int lo = 0;
        for (int x: A) {
            if (lo <= 1 || x != A[lo - 2]) {
                A[lo] = x;
                lo++;
            }
        }
        return lo;
    }
};

