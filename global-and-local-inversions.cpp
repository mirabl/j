class Solution {
public:
    int countLocalInversions(vector<int>& A) {
        int N = A.size();
        int res = 0;
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                res++;
            }
        }
        return res;
    }
    
    int countGlobalInversions2(vector<int>& A) {
        int N = A.size();
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (A[i] > A[j]) {
                    res++;
                }
            }
        }
        return res;
    }
    
       
    int countGlobalInversions3(vector<int>& A) {
        int N = A.size();
        int res = 0;

        set<int> remaining;
        for (auto x: A) {
            remaining.insert(x);
        }
        
        for (int i = 0; i < N; i++) {
            remaining.erase(A[i]);
            for (int y: remaining) {
                if (y < A[i]) {
                    res++;
                }
            }
        }
        
        return res;
    }
     
      int countGlobalInversions(vector<int>& A) {
        int N = A.size();
        int res = 0;
        int B = 100;
        int numBuckets = 1 + N / B;
          
        vector<set<int>> remaining(numBuckets);
        for (auto x: A) {
            remaining[x / B].insert(x);
        }
        
        for (int i = 0; i < N; i++) {
            int x = A[i];
            remaining[x / B].erase(x);
            
            for (int y: remaining[x / B]) {
                if (y < x) {
                    res++;
                }
            }
            for (int j = 0; j < x / B; j++) {
                res += remaining[j].size();
            }
        }
        
        return res;
    }  
    bool isIdealPermutation(vector<int>& A) {
        int numLocalInversions = countLocalInversions(A);
        int numGlobalInversions = countGlobalInversions(A);
        cout << "glo " << numGlobalInversions << endl;
        cout << "loc " << numLocalInversions << endl;
        return numLocalInversions == numGlobalInversions;
    }
};
