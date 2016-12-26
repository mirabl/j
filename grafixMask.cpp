/*
https://community.topcoder.com/stat?c=problem_statement&pm=2998&rd=5857
{"0 292 399 307"}
Returns: { 116800,  116800 }

	
{"48 192 351 207", "48 392 351 407", "120 52 135 547", "260 52 275 547"}
Returns: { 22816,  192608 }

2)	
    	
{"0 192 399 207", "0 392 399 407", "120 0 135 599", "260 0 275 599"}
Returns: { 22080,  22816,  22816,  23040,  23040,  23808,  23808,  23808,  23808 }

3)	
    	
{"50 300 199 300", "201 300 350 300", "200 50 200 299", "200 301 200 550"}
Returns: { 1,  239199 }
4)	
    	
{"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
 "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
 "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
 "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
 "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
 "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
 "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
 "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
 "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
 "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
 "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
 "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
 "373 0 373 599", "389 0 389 599"}
Returns: 
{ 15,  30,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  100,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  200,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345 }


alias a='g++ grafixMask.cpp -Wall  -g  && ./a.out < grafixMask.1.in '

diff <(./a.out < grafixMask.0.in) grafixMask.0.out
diff <(./a.out < grafixMask.1.in) grafixMask.1.out
diff <(./a.out < grafixMask.2.in) grafixMask.2.out
diff <(./a.out < grafixMask.3.in) grafixMask.3.out

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

const int N = 400;
const int M = 600;
bool visited[N][M];


// Recursive uses too much stack.
// int exploreRegion(int row, int col) {
// 	if (row >= N || col >= M || row < 0 || col < 0)
// 		return 0;
// 	if (visited[row][col])
// 		return 0;
// 	visited[row][col] = true;

// 	int size = 1;
// 	if (!visited[row + 1][col]) {
// 		size += exploreRegion(row + 1, col);
// 	}
// 	if (!visited[row][col + 1]) {
// 		size += exploreRegion(row, col + 1);
// 	}
// 	if (!visited[row - 1][col]) {
// 		size += exploreRegion(row - 1, col);
// 	}
// 	if (!visited[row][col - 1]) {
// 		size += exploreRegion(row, col - 1);
// 	}
// 	return size;
// 	// return 1 + exploreRegion(row + 1, col) + exploreRegion(row, col + 1) + exploreRegion(row - 1, col) + exploreRegion(row, col - 1);
// }



int main() {
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			visited[row][col] = false;
		}
	}

	int row1, col1, row2, col2;
	while (cin >> row1 >> col1 >> row2 >> col2) {
		for (int row = row1; row < row2 + 1; ++row) {
			for (int col = col1; col < col2 + 1; ++col) {
				visited[row][col] = true;
			}
		}
	}
	vector<int> sizes;
	stack<pair<int, int> > to_visit;
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			if (!visited[row][col]) {
				to_visit.push(pair<int, int>(row, col));
				int size = 0;
				while(!to_visit.empty()) {
					pair<int, int> p = to_visit.top();
					to_visit.pop();
					int cur_row = p.first;
					int cur_col = p.second;
					if (cur_row < 0 || cur_row >= N || cur_col < 0 || cur_col >= M) {
						continue;
					}
					if (!visited[cur_row][cur_col]) {
						size += 1;
						visited[cur_row][cur_col] = true;
						to_visit.push(pair<int, int>(cur_row + 1, cur_col));
						to_visit.push(pair<int, int>(cur_row - 1, cur_col));
						to_visit.push(pair<int, int>(cur_row, cur_col + 1));
						to_visit.push(pair<int, int>(cur_row, cur_col - 1));
					}
				}
				sizes.push_back(size);			
			}
		}
	}
	sort(sizes.begin(), sizes.end());
	for (int i = 0; i < (int)sizes.size(); ++i) {
		cout << sizes[i] << endl;
	}

	return 0;
}