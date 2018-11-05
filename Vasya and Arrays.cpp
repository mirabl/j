#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        A.push_back(t);
    }
    int m;
    cin >> m;
    vector<int> B;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        B.push_back(t);
    }

    map<int, int> M;
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += A[i];
        M[s] = i;
    }

    int res = 0;
    int i = 0;
    int done = 0;
    while (i < m) {
        int cur = 0;
        int j = i;
        while (j < m) {
            cur += B[j];

            if (M.count(cur + done) == 1) {
                res++;
                done += cur;
                i = j + 1;
                break;
            } else {
                if (j == m - 1) {
                    cout << "-1" << endl;
                    return 0;
                }
                j++;
            }
        }
    }
    cout << res << endl;
}