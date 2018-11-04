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