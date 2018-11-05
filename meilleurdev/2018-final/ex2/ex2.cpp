#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <tuple>
#include <deque>
#include <cstring>
#include <set>
#include <cassert>
#include <iomanip>

#include "exercise.hpp"
using namespace std;

typedef long long LL; typedef stringstream SS; typedef vector<int> VI; typedef vector<string> VS;
typedef vector<VI> VVI; typedef vector<VS> VVS; typedef pair<int, int> PII;
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
const int oo = 1<<29;
#define LOCALPRINT(a) do { SS ss; ss << a; localPrint(ss.str()); } while (0)
#define DUMPINPUT() SS cin; string line; while(getline(std::cin, line)) { cin << line << endl; LOCALPRINT(line); }

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N;
    cin >> N;
    vector<vector<int>> G(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int t;
            cin >> t;
            G[i][j] = t;
        }
    }
    
    vector<int> atSame(N, 0);

    int bi = 0;
    for (int i = 0; i < N; i++) {
        int r = 0;
        for (int j = 0; j < N; j++) {
            if (G[i][j] == 1) {
                r += 1;
            }
        }
        atSame[i] = r;
        if (r > atSame[bi]) {
            bi = i;
        }
    }



    set<int> clique;
    clique.insert(bi);

        for (int j = 0; j < N; j++) {
            bool inAll = true;

            for (auto c: clique) {
                if (G[c][j] != 1) {
                    inAll = false;
                }
            }

            if (inAll) {
                clique.insert(j);
            }
    }

  


    cout << clique.size() << endl;
    return;
}