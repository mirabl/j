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


#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}



ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    vector<string> V = split(string("a b c d"), ' ');
    for (auto x: V) {
        cout << x << endl;
    }
}