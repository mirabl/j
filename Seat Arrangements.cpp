#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int r = 0;
    vector<vector<char>> G(n, vector<char>(m));
    for (int row = 0; row < n; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < m; col++) {
            G[row][col] = s[col];
        }
    }

    for (int row = 0; row < n; row++) {
        int l = 0;
        for (int col = 0; col < m; col++) {
            if (G[row][col] == '.') {
                l++;
            } else {
                if (l >= k) {
                    r += l - k + 1;
                }
                l = 0;
            }
        }
        if (l >= k) {
            r += l - k + 1;
        }
    }

    for (int col = 0; col < m; col++) {
        int l = 0;
        for (int row = 0; row < n; row++) {
            if (G[row][col] == '.') {
                l++;
            } else {
                if (l >= k && k > 1) {
                    r += l - k + 1;
                }
                l = 0;
            }
        }
        if (l >= k && k > 1) {
            r += l - k + 1;
        }
    }
    cout << r << endl;
    return 0;
}