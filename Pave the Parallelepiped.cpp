// https://codeforces.com/contest/1008/problem/D
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int M = 100000 + 1;

vector<int> div(int n) {
    vector<int> d(M, 0);
    int c = 0;
    for (int x = n; x >= 1; x--) {
        if (n % x == 0) {
            c++;
            d[x] = c;
        }
    }
    return d;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        vector<int> v{A, B, C};
        sort(v.begin(), v.end());
        A = v[0];
        B = v[1];
        C = v[2];

        vector<int> dC = div(C);

        int res = 0;
        for (int x = 1; x <= A; x++) {
            if (A % x == 0) {
                for (int y = x; y <= B; y++) {
                    if (B % y == 0) {
                        res += dC[y];
                    }
                }
            }
        }
        cout << res << endl;
    }
}