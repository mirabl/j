/*
https://www.facebook.com/hackercup/problem/180494849326631/
alias a='g++ -Wall -std=c++11 let_it_flow.cpp'
alias b='./a.out < let_it_flow_sample_input.txt'

a && diff <(./a.out < let_it_flow.2.in) let_it_flow.2.out
a && paste -s <(./a.out < let_it_flow.2.in) let_it_flow.2.out

a && diff <(./a.out < let_it_flow_sample_input.txt) let_it_flow_sample_output.txt 
a && paste -s <(./a.out < let_it_flow_sample_input.txt) let_it_flow_sample_output.txt 


*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isFree(int row, int col, vector<string>& lines, int N) {
	if (row >= 0 && col >= 0 && row < 3 && col < N + 1) {
		if (col == N) {
			return true;
		}
		return lines[row][col] == '.';
	}
	return false;
}


void printG(vector<vector<ll> >& G, int N) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < N + 1; col++) {
			cerr << G[col][row] << " ";
		}
		cerr << endl;
	}
}

int main() {
	/* 

Input Input begins with an integer T, the number of houses. For each house,
there is first a line containing the integer N. Then, 3 lines follow, each
containing a string of length N containing only the characters . and #. The
jth character of the ith line is Gi,j.

Output For the ith house, print a line containing "Case #i: " followed by the
number of different valid sets of pipes which could be installed in the ith
house (modulo 1,000,000,007).

Constraints
1 ≤ T ≤ 100 
1 ≤ N ≤ 1,000 

	*/
/*

...#
....
.#..

*/
	
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<string> lines;
		string line;
		cin >> line;
		lines.push_back(line);
		cin >> line;
		lines.push_back(line);
		cin >> line;
		lines.push_back(line);

		ll mod = 1000000007ll;
		ll res = 0;

		vector<vector<ll> > G(N + 1, vector<ll>(3));
		G[0][0] = lines[0][0] == '.' ? 1 : 0;

													//printG(G, N); cerr << endl;		

		for (int col = 0; col < N; col++) {
													//cerr << "* col = " << col << endl;			
			for (int row = 0; row < 3; row++) {
				if (G[col][row] == 0) {
													//cerr << "\t(skip row=" << row << ")" << endl;	
					continue;
				}				
													//cerr << "\trow = " << row << "\t" << "G[col][row] " << "= "  << G[col][row] << endl;				
				for (int d: vector<int>{-1, 1}) {
					int col2 = col + 1;
					int row2 = row + d;
												//cerr << "\t\t  iF row=" << row2 << " col=" << col2 << " " << (isFree(row2, col2, lines, N) ? "yes" : "no") << endl;
												//cerr << "\t\t+ iF row=" << row2 << " col=" << col << " " << (isFree(row2, col, lines, N) ? "yes" : "no") << endl;

					if (isFree(row2, col2, lines, N) && isFree(row2, col, lines, N)) 
					{
						G[col2][row2] = (G[col][row] + G[col2][row2]) % mod;
					}
				}
													//	printG(G, N); cerr << endl;		
			}
		}

		res = G[N][2];
													//	printG(G, N); cerr << endl;		

		cout << "Case #" << t << ": " << res << endl;
	}
}