/*
https://community.topcoder.com/stat?c=problem_statement&pm=14083
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class BearSlowlySorts {
public:
	int minMoves(vector<int> w) {
		int min_i = 0;
		int max_i = 0;
		const int n = int(w.size());
		bool sorted = true;
		for (int i = 0; i < n; ++i) {
			if (w[i] < w[min_i]) {
				min_i = i;
			}
			if (w[i] > w[max_i]) {
				max_i = i;
			}
			if (i < n - 1 && w[i] > w[i + 1]) {
				sorted = false;
			}
		}
		if (sorted) {
			return 0;
		}

		int num_inplace = 0;
		if (min_i == 0) {
			num_inplace++;
		}
		if (max_i == n - 1) {
			num_inplace++;
		}

		if (num_inplace == 2) {
			return 1;
		} else if (num_inplace == 1) {
			return 1;
		} else { // 0
			int num_goodpart = 2;
			if (min_i == n - 1) {
				num_goodpart--;
			}
			if (max_i == 0) {
				num_goodpart--;
			}
			if (num_goodpart >= 1) {
				return 2;
			} else {
				return 3;
			}
		}
		return -1; // Never reached.
	}
};