#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> f(map<int, vector<int>>& G, int n, int k) {
    vector<int> d(n, 1);

    for (int kk = 2; kk <= k; kk++) {
        vector<int> dNew(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto v: G[i]) {
                dNew[i] += d[v];
            }
        }
        swap(d, dNew);
    }
    return d;
}

int main() {
    int n1, n2, k;
    cin >> n1 >> n2 >> k;
    map<int, vector<int>> G1, G2;
    for (int i = 0; i < n1 - 1; i++) {
        int u, v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
    }
    for (int i = 0; i < n2 - 1; i++) {
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
    }

    vector<int> numPathSelfLength1 = f(G1, n1, k);




}