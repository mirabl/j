// https://codeforces.com/contest/1008/problem/C
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    int i = 0;
    int j = 0;
    int res = 0;
    while (i < n) {
        if (a[i] > a[j]) {
            j++;
            res++;
        }
        i++;
    }
    cout << res << endl;
}