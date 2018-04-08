class Solution {
public:
    typedef pair<int, int> frac;

    struct CustomCompare
    {
        bool operator()(const frac& lhs, const frac& rhs)
        {
            return rhs.second * lhs.first > rhs.first * lhs.second;
        }
    };
    
    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        priority_queue<frac, vector<frac>, CustomCompare> Q;
        map<int, int> primeToIndex;
        for (int i = 0; i < N; i++) {
            primeToIndex[A[i]] = i;
        }
        
        for (int i = 1; i < N; i++) {
            Q.push(frac{1, A[i]});
        }
        
        for (int i = 1; i < K; i++) {
            auto f = Q.top();
            Q.pop();
            int j = primeToIndex[f.first];
            if (j < N - 1) {
                Q.push(frac{A[j + 1], f.second});
            }
        }
        return {Q.top().first, Q.top().second};
    }
};
