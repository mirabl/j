// https://www.spoj.com/submit/MST/
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> G;
int INFTY = 1e8;

int main() {
	cin >> N >> M;
	G = vector<vector<pair<int, int>>>(N);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	
	vector<int> D(N, INFTY);
	D[0] = 0;
	for (auto e: G[0]) {
		D[e.first] = e.second;
	}
	
    int ww = 0;

	for (int i = 0; i < N - 1; i++) {
		int bu = -1;
        for (int u = 0; u < N; u++) {
            if (D[u] != 0 && D[u] != INFTY) {
                if (bu == -1 || D[u] < D[bu]) {
                    bu = u;
                }
            }
        }

        ww += D[bu];
        for (auto e: G[bu]) {
            int v = e.first;
            int w = e.second;
            D[v] = min(D[v], w);
        }
        D[bu] = 0;
	}

    cout << ww << endl;
	
	return 0;
}


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

