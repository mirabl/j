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




// prim
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<vector<pair<int, int>>> G;
int INFTY = 11111111;

int prim() {
    int tw = 0;
    set<int> S;
    vector<int> d(N, INFTY);
    S.insert(0);
    d[0] = 0;
    for (auto p: G[0]) {
        d[p.first] = p.second;
    }

    while (S.size() != N) {
        int nextJ = -1;
        for (int j = 0; j < N; j++) {
            if (S.count(j) == 1) {
                continue;
            }
            if (nextJ == -1 || d[j] < d[nextJ]) {
                nextJ = j;
            }
        }
        tw += d[nextJ];
        S.insert(nextJ);
        for (auto p: G[nextJ]) {            
            d[p.first] = min(d[p.first], p.second);
        }
    }
    return tw;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    for (int m = 0; m < M; m++) {
        int i, j, k;
        cin >> i >> j >> k;
        i--;
        j--;
        G[i].push_back({j, k});
        G[j].push_back({i, k});
    }

    int res = prim();

    cout << res << endl;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10000 + 1];

int do_find(int u) {
    if (parent[u] != u) {
        parent[u] = do_find(parent[u]);
    }
    return parent[u];
}

void do_union(int u, int v) {
    parent[do_find(u)] = do_find(v);
}

int main() {
	
	int N, M;
	cin >> N;
	cin >> M;

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges.push_back({w, {u, v}});
    }

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int totalw = 0;
    for (auto edge: edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (do_find(u) == do_find(v)) {
            continue;
        }
        do_union(u, v);
        totalw += w;
    }
    cout << totalw << endl;
	return totalw;
}



// Prim
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	
	int N, M;
	cin >> N >> M;
	vector<set<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		G[u].insert({v, w});
		G[v].insert({u, w});
	}
	
	vector<bool> done(N, false);
	int kInfinity = 1e8;
	vector<int> dist(N, kInfinity);
	dist[0] = 0;
	int totalWeight = 0;
	
	while (true) {
		int next = -1;
		for (int i = 0; i < N; i++) {
			if (done[i]) {
				continue;
			}
			if (next == -1 || dist[i] < dist[next]) {
				next = i;
			}
		}
		if (next == -1) {
			break;
		}
		
		for (auto p: G[next]) {
			dist[p.first] = min(dist[p.first], p.second);
		}
		
		totalWeight += dist[next];
		done[next] = true;
	}

	return totalWeight;
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int do_find(vector<int>& UF, int x) {
	if (UF[x] != x) {
		UF[x] = do_find(UF, UF[x]);
	}
	return UF[x];
}

void do_union(vector<int>& UF, int x, int y) {
	UF[do_find(UF, x)] = do_find(UF, y);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());
	
	int totalWeight = 0;
	int nEdges = 0;
	
	vector<int> UF(N);
	for (int i = 0; i < N; i++) {
		UF[i] = i;
	}
	
	int i = 0;
	while (nEdges != N - 1) {
		auto edge = edges[i];
		i++;
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if (do_find(UF, u) != do_find(UF, v)) {
			do_union(UF, u, v);
			totalWeight += w;
			nEdges++;
		}
	}
	
	return totalWeight;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> UF(10000 + 1);

int do_find(int x) {
	if (UF[x] != x) {
		UF[x] = do_find(UF[x]);
	}
	return UF[x];
}

void do_union(int x, int y) {
	UF[do_find(x)] = do_find(y);
}

int main() {
	
	int N, M;
	cin >> N >> M;
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		edges.push_back({w, {u, v}});
	}
	int tw = 0;
	int k = 0;
	sort(edges.begin(), edges.end());
	
	for (int i = 0; i < N; i++) {
		UF[i] = i;
	}
	
	for (int i = 0; i < int(edges.size()) && k < N - 1; i++) {
		auto edge = edges[i];
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		if (do_find(u) != do_find(v)) {
			k++;
			do_union(u, v);
			tw += w;
		}
	}

	cout << tw << endl;
}


// Prim
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<pair<int, int>>> G(N);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u - 1].push_back({v - 1, w});
	}
	int infty = 1e8;
	vector<int> D(N, infty);
	D[0] = 0;
	set<int> done;
	
	int tw = 0;
	
	while (done.size() != N) {
		int next = -1;
		for (int i = 0; i < N; i++) {
			if (!done.count(i) && (next == -1 || D[i] < D[next])) {
				next = i;
			}
		}
		if (next == -1) {
			break;
		}
		for (auto p: G[next]) {
			D[p.first] = min(D[p.first], p.second);
		}
		done.insert(next);
		tw += D[next];
	}
	
	return tw;
}
 
