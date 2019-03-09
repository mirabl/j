class Solution {
public:
    int n;
    
    bool psq(int x, int y) {
        int z = sqrt(x + y);
        return z * z == x + y;
    }
    
    int r(vector<int>& A, int offset) {
        if (offset == n) {
            return 1;
        }
        
        int res = 0;
        set<int> done;
        for (int i = offset; i < n; i++) {
            if (done.count(A[i]) == 1) {
                continue;
            }
            done.insert(A[i]);
            if (!psq(A[offset - 1], A[i])) {
                continue;
            }
            
            swap(A[i], A[offset]);
            res += r(A, offset + 1);
            
            swap(A[i], A[offset]);
        }
        return res;
    }
    
    int numSquarefulPerms(vector<int>& A) {
        n = A.size();
        
        int res = 0;
        set<int> done;
        for (int i = 0; i < n; i++) {
            if (done.count(A[i]) == 1) {
                continue;
            }
            done.insert(A[i]);

            swap(A[i], A[0]);
            res += r(A, 1);
            swap(A[i], A[0]);
        }
        
        return res;
    }
};
