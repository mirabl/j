#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;
    int res = 0;
    int lastfree = 0;
    for (int i = 0; i < n; i++) {
        int t, l;
        cin >> t >> l;

        if (lastfree + a <= t) {
            res += (t - lastfree) / a;
        }
        lastfree = t + l;
    }
    res += (L - lastfree) / a;
    cout << res << endl;
}
