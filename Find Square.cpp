#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nrows, ncols;
    cin >> nrows >> ncols;
    int minrow = 1000, maxrow = 0, mincol = 1000, maxcol = 0;
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            char c;
            cin >> c;
            if (c == 'B') {
                minrow = min(minrow, row);
                maxrow = max(maxrow, row);
                mincol = min(mincol, col);
                maxcol = max(maxcol, col);
            }
        }
    }
    cout << (1 + (minrow + maxrow) / 2) << " " << (1 + (mincol + maxcol) / 2) << endl;
}