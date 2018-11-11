#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int do_find(int x) {
    if (parent[x] != x) {
        parent[x] = do_find(parent[x]);
    }
    return parent[x];
}

void do_union(int x, int y) {
    parent[do_find(x)] = do_find(y);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> edges;
    for (int l = 0; l < M; l++) {
        int i, j, k;
        cin >> i >> j >> k;
        i--;
        j--;
        edges.push_back({k, {i, j}});
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i < N; i++) {
        parent.push_back(i);
    }

    int w = 0;
    for (auto edge: edges) {
        if (do_find(edge.second.first) == do_find(edge.second.second)) {
            continue;
        }
        do_union(edge.second.first, edge.second.second);
        w += edge.first;
    }

    cout << w << endl;
    return 0;
}