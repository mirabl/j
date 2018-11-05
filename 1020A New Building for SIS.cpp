#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    for (int i = 0; i < k; i++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;

        int d = 0;
        int f = fa;
        if (ta != tb) {
            if (fa < a) {
                d += a - fa;
                f = a;
            } else if (fa > b) {
                d += fa - b;
                f = b;
            } else {
                f = fa;
            }
            d += abs(tb - ta);
        }

        d += abs(fb - f);
        cout << d << endl;
    }
}