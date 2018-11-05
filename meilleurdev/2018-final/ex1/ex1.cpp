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
    int M;
    cin >> M;

    vector<vector<double>> V(N, vector<double>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double f;
            cin >> f;
            V[i][j] = f;
        }
    }


    vector<double> D(N, 0);
    D[0] = 10000;

    for (int i = 0; i < M; i++) {
    //    cout << "i= " << i << endl;
        vector<double> E(N, 0);

        for (int j = 0; j < N; j++) {

            // obtenir devise j
            double r = 0;
            for (int k = 0; k < N; k++) {
                double z = D[k] * V[k][j];
                r = max(r, z);
            }
            E[j] = r;
        }

        swap(E, D);
   //     cout << "end of i=" << i << endl;
    }

   // cout << "b" << endl;

    double best = 0;
    for (int i = 0; i < N; i++) {
        best = max(best, D[i]);
    }

    cout << D[0] << endl;

}