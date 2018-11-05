// https://codeforces.com/contest/1011/problem/A
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int w = 0;
    int i = 0;
    int nStages = 0;
    while (i < s.size()) {
        w += (s[i] - 'a' + 1);
        nStages++;

        int j = i + 1;
        while (j < s.size() && s[j] < s[i] + 2) {
            j++;
        }
        i = j;
        
        if (nStages == k) {
            break;
        }
    }
    cout << (nStages == k ? w : -1) << endl;
}