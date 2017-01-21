#include <vector>
#include <string>
#include <sstream>
using namespace std;

class ThreeTeleports {
public:
  int dist(int xa, int ya, int xb, int yb) {
  	return abs(xb - xa) + abs(yb - ya);
  }

  int shortestDistance(int xMe,
                       int yMe,
                       int xHome,
                       int yHome,
                       vector<string> const &teleports) {
  	const int num_nodes = 8;
  	long long M[num_nodes][num_nodes];
  	for (int i = 0; i < num_nodes; i++) {
  		for (int j = 0; j < num_nodes; j++) {
  			M[i][j] = -1;
  		}
  	}

  	const int start_node = 0;
  	const int end_node = 1;
  	M[start_node][end_node] = dist(xMe, yMe, xHome, yHome);
  	vector<int> xA, yA, xB, yB;
  	for (int i = 0; i < 3; i++) {
  		istringstream iss(teleports[i]);
  		int xa, ya, xb, yb;
  		iss >> xa >> ya >> xb >> yb;
  		xA.push_back(xa);
  		yA.push_back(ya);
  		xB.push_back(xb);
  		yB.push_back(yb);
  	}

  	// FIXME: read points and do generic distance computation instead.
  	// set teleport distance after.
  	for (int i = 0; i < 3; i++) {
  		M[2 + 2 * i][2 + 2 * i + 1] = 10;
  		M[2 + 2 * i + 1][2 + 2 * i] = 10;
  		M[start_node][2 + 2 * i] = dist(xMe, yMe, xA[i], yA[i]);
  		M[start_node][2 + 2 * i + 1] = dist(xMe, yMe, xB[i], yB[i]);
  		M[2 + 2 * i + 1][end_node] = dist(xB[i], yB[i], xHome, yHome);
  		M[2 + 2 * i][end_node] = dist(xA[i], yA[i], xHome, yHome);
  		for (int j = 0; j < 3; j++) {
  			if (i == j) {
  				continue;
  			}
  			M[2 + 2 * i][2 + 2 * j] = dist(xA[i], yA[i], xA[j], yA[j]);
  			M[2 + 2 * i + 1][2 + 2 * j] = dist(xB[i], yB[i], xA[j], yA[j]);

  			M[2 + 2 * i][2 + 2 * j + 1] = dist(xA[i], yA[i], xB[j], yB[j]);
  			M[2 + 2 * i + 1][2 + 2 * j + 1] = dist(xB[i], yB[i], xB[j], yB[j]);
  		}
	}

	// FW
	for (int k = 0; k < num_nodes; k++) {
		for (int i = 0; i < num_nodes; i++) {
			for (int j = 0; j < num_nodes; j++) {
				if (M[i][k] != -1 && M[k][j] != -1) {
					if (M[i][j] == -1 || M[i][j] > M[i][k] + M[k][j]) {
						M[i][j] = M[i][k] + M[k][j];	
					}
				}
			}
		}
	}

    return M[start_node][end_node];
  }
};
