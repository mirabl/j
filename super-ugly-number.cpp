class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int> Q;
        Q.push(- 1);
        int last = 0;
        for (int i = 0; i < n; i++) {
            int x = - Q.top();
            while (x == last) {
                Q.pop();
                x = - Q.top();
            }
            last = x;
            for (int p: primes) {
                int y = - x * p;
                if (y / p == - x) {
                    Q.push(- x * p);
                }
            }
        }
        return - Q.top();
    }
};