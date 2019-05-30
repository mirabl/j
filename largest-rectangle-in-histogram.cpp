class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
        stack<int> S;
        A.insert(A.begin(), 0);
        A.push_back(0);
        int res = 0;
        int n = A.size();

        for (int i = 0; i < n; i++) {
            while (!S.empty() && A[S.top()] > A[i]) {
                int j = S.top();
                S.pop();
                int k = S.empty() ? 0 : S.top() + 1;
                res = max(res, (i - 1 - k + 1) * A[j]);
            }
            S.push(i);
        }
        return res;        
    }
};

