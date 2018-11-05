#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = int(s.size());


    for (int i = 0; i < n; ) {
        // cout << "i=" << i << " s=" << s << endl;
        if (s[i] == '0') {
            i++;
            continue;
        }
        if (s[i] == '2') {
            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    found = true;
                    for (int k = j - 1; k >= i; k--) {
                        swap(s[k], s[k + 1]);
                    }
                    i = j + 1;
                    continue;
                    break;
                }
            }
            if (!found) {
                i++;
            }
        }
        if (s[i] == '1') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '2') {
                    break;
                } else if (s[j] == '0') {
                    swap(s[i], s[j]);
                }
            }
            i++;
        }
        // cout << s << endl;  
    }
    cout << s << endl;
}

/*

20201

12020




*/