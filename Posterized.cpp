/*

0 1 2 3 4 5 6 ....        255
<    k    > <    k    >

160 26 33 71 ...




*/
#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (i > 0) {
            cout << " ";
        }
        cout << (k * (t / k));
    }
    cout << endl;
}