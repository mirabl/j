/*
Backtracking:
Find all permutations or combinations
Find all possible subsets (2 ways)
N queens problem
Convert numbers into words according to letters on an old phone keypad
*/
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<char>& v);

void print_permutations_rec(vector<char>& v, int start) {
	int n = int(v.size());
	if (start == n) {
		print_vector(v);
	}
	for (int i = start; i < n; i++) {
		swap(v[i], v[start]);
		print_permutations_rec(v, start + 1);
		swap(v[i], v[start]);
	}
}

void print_permutations(vector<char>& v) {
	print_permutations_rec(v, 0);
}


void print_combinations_rec(vector<char>& v, vector<char>& cur, int k, int start) {
	const int n = int(v.size());
	if (k == 0) {
		print_vector(cur);
		return;
	}
	if (start >= n) {
		return;
	}
	cur.push_back(v[start]);
	print_combinations_rec(v, cur, k - 1, start + 1);
	cur.pop_back();
	print_combinations_rec(v, cur, k, start + 1);
}

void print_combinations(vector<char>& v, int k) {
	vector<char> cur;
	print_combinations_rec(v, cur, k, 0);
}


void print_subsets_bits(vector<char>& v) {
	const int n = int(v.size());
	for (int x = 0; x < (1 << n); x++) {
		for (int j = 0; j < n; j++) {
			if (((x >> j) & 1) == 1) {
				cout << v[j] << " ";
			}
		}
		cout << endl;
	}
}

void print_subsets_rec(vector<char>& v, vector<char>& cur, int start) {
	if (start == int(v.size())) {
		print_vector(cur);
		return;
	}
	print_subsets_rec(v, cur, start + 1);
	cur.push_back(v[start]);
	print_subsets_rec(v, cur, start + 1);
	cur.pop_back();
}

void print_subsets(vector<char>& v) {
	vector<char> cur;
	print_subsets_rec(v, cur, 0);
}

/* ********************* */

void print_vector(vector<char>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int n = 3;
	vector<char> v;
	for (int i = 0; i < n; i++) {
		v.push_back('a' + i);
	}
	print_permutations(v);

	cout << endl;

	print_combinations(v, 2);

	cout << endl;

	print_subsets_bits(v);
	cout << endl;
	print_subsets(v);
}