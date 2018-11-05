// https://codeforces.com/contest/1008/problem/B
#include <iostream>
#include <vector>

using namespace std;

int n;
int INFTY = 1000000000 + 1;

int main() {
    cin >> n;

    int last = INFTY;

    for (int i = 0; i < n; i++) {
        int w;
        int h;
        cin >> w >> h;
        int M = max(w, h);
        int m = min(w, h);
        if (M <= last) {
            last = M;
        } else if (m <= last) {
            last = m;
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}