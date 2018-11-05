#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        c.push_back(tmp);
    }
    vector<int> a;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int j = 0;
    int res = 0;
    for (int i = 0; i < n && j < m; i++) {
        if (a[j] >= c[i]) {
            j++;
            res++;
        }
    }
    cout << res << endl;
}