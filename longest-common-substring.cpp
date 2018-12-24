/*
alias a='g++ longest_common_substring.cpp -Wall && ./a.out '


*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define max3(x,y,z) max(max((x), (y)), (z))

string longest_common_substring(const string& s, const string& t)
{
	string res;

	int N = s.size();
	int M = t.size();
	int A[N + 1][M + 1];

	pair<int,int> pointers[N+1][M+1]; 
	// vector<pair<int,int> > pointers; 

	for (int i = 0; i < N + 1; ++i) {
		A[i][0] = 0;
	}
	for (int j = 0; j < M + 1; ++j) {
		A[0][j] = 0;
	}
 
	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			int x = 0;
			if (s[i - 1] == t[j - 1])
				x = 1;
			A[i][j] = max3(A[i-1][j-1] + x, A[i-1][j], A[i][j-1]);

			int m = max3(A[i-1][j-1] + x, A[i-1][j], A[i][j-1]);
			if (m == A[i][j-1]) {
				pointers[i][j] = pair<int, int>(i, j-1);
			} else if (m == A[i-1][j]) {
				pointers[i][j] = pair<int, int>(i-1, j);
			} else {
				pointers[i][j] = pair<int, int>(i-1, j-1);
			}

		}
	}

	int i = N;
	int j = M;

	while (!(i == 0 && j == 0)) {
		int next_i = pointers[i][j].first;
		int next_j = pointers[i][j].second;

		if (next_i == i - 1 && next_j == j - 1) {
			res.insert(0, 1, s[i - 1]);
		}
		i = next_i;
		j = next_j;
	}
	return res;
}

int main()
{
	string lcs = longest_common_substring("abcdef", "zcdegk");
	cout << lcs << endl;
}