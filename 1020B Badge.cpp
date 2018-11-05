#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        p.push_back(tmp - 1);
    }

    vector<int> res;
    for (int start = 0; start < n; start++) {
        set<int> visited;
        int i = start;
        while (true) {
            if (visited.count(i) == 1) {
                res.push_back(i + 1);
                break;
            }
            visited.insert(i);
            i = p[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
}