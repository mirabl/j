#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> UF;

int find(int u) {
    if (UF[u] != u) {
        UF[u] = find(UF[u]);
    }

    return UF[u];
}

void do_union(int u, int v) {
    UF[find(u)] = find(v);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u - 1, v - 1}});
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i < N; i++) {
        UF.push_back(i);
    }

    int ne = 0;
    int tw = 0;
    for (auto edge: edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) == find(v)) {
            continue;
        }

        do_union(u, v);
        ne++;
        tw += edge.first;
        if (ne == N - 1) {
            break;
        }
    }

    cout << tw << endl;
}