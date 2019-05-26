// segment tree
class NumArray {
public:
    vector<int> T;
    int N;
    int n;
    NumArray(vector<int> nums) {
        n = nums.size();
        N = 1;
        while (N < n) {
            N *= 2;
        }
        T.resize(2 * N);
        for (int i = 0; i < n; i++) {
            T[N + i] = nums[i];
        }
        for (int i = N - 1; i >= 1; i--) {
            T[i] = T[2 * i] + T[2 * i + 1];
        }       
    }
    
    void update(int i, int val) {
        int j = N + i;
        int diff = val - T[j];
        while (j > 0) {
            T[j] += diff;
            j /= 2;
        }
    }
    
    int s(int i, int j, int root, int left, int right) {
        int middle = (left + right) / 2;        
        if (i == left && j == right) {
            return T[root];
        } else if (j <= middle) {
            return s(i, j, 2 * root, left, middle);
        } else if (i >= middle + 1) {
            return s(i, j, 2 * root + 1, middle + 1, right);
        } else {
            return s(i, middle, 2 * root, left, middle) + s(middle + 1, j, 2 * root + 1, middle + 1, right);
        }
        
    }
    
    int sumRange(int i, int j) {
        return s(i, j, 1, 0, N - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */


// sqrt
class NumArray {
public:
    vector<int> A;
    int n; 
    int m;
    vector<int> B;
    
    NumArray(vector<int>& nums) {
        A = nums;
        n = A.size();
        m = n > 0 ? sqrt(n) : 1;
        B.resize(1 + (n / m));
        for (int i = 0; i < n; i++) {
            B[i / m] += A[i];
        }
        
    }
    
    void update(int i, int val) {
        int diff = val - A[i];
        A[i] += diff;
        B[i / m] += diff;
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        int k = i;
        while (k <= j) {
            if (k % m == 0 && j >= k + m) {
                res += B[k / m];
                k += m;
            } else {
                res += A[k];
                k++;
            }
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
