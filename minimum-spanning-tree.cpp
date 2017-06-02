/*http://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/

/* Finds the sum of weights of the edges of the Minimum Spanning Tree.
    Graph is represented as adjacency list using array of vectors.  MAX 
    is an upper  limit on number of vertices.
   g[u] represents adjacency list of vertex u,  Every element of this list 
   is a pair<w,v>  where v is another vertex and w is weight of edge (u, v)
  Note : Vertex numbers start with 1 and don't need to be contiguous.   */
// Prim. O(V^2)
int spanningTree(vector <pair<int,int> > g[], int MAX)
{
	int total_weight = 0;
	vector<int> dist(MAX, INT_MAX);
	bool first = true;
	while (true) {
	    int next_node = -1;
	    for (int i = 0; i < MAX - 1; i++) {
	        if (g[i].size() != 0 && (next_node == -1 || dist[i] < dist[next_node])) {
	            next_node = i;
	        }
	    }
	    if (first) {
	        dist[next_node] = 0;
	        first = false;
	    }
	    if (next_node == -1) {
	        break;
	    }
        for (pair<int, int> p: g[next_node]) {
            int w = p.first;
            int v = p.second;
            dist[v] = min(dist[v], w);
        }
        total_weight += dist[next_node];
        g[next_node].clear();
	}
	return total_weight;
}


