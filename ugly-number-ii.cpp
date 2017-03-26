class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> Q;
        Q.push(1);
        set<int> done;
        vector<int> mult{2, 3, 5};
        while (n > 1) {
            int x = Q.top();
            Q.pop();
            for (int m: mult) {
                if (done.count(x * m) == 0 && (x*m)/m == x) {
                    Q.push(x * m);
                    done.insert(x * m);
                }
            }
            n--;
        }
        return Q.top();
    }
};

// better: https://discuss.leetcode.com/topic/33968/shortest-o-n-java-dp-solution