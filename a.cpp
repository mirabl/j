/*
permutations
combinations
subsets (bits, recursive)
*/


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


void permutations_rec(vector<char>& v, int offset, vector<vector<char>>& res) {
	if (offset == v.size()) {
		res.push_back(v);
	} else {
		for (int i = offset; i < v.size(); i++) {
			swap(v[i], v[offset]);
			permutations_rec(v, offset + 1, res);
			swap(v[i], v[offset]);
		}
	}
}

vector<vector<char>> permutations(vector<char>& v) {
	vector<vector<char>> res;
	permutations_rec(v, 0, res);
	return res;
}

vector<vector<char>> subsets_bits(vector<char>& v) {
	const int n = v.size();
	vector<vector<char>> res;
	for (int x = 0; x < 1<<n; x++) {
		vector<char> V;
		for (int i = 0; i < n; i++) {
			if (((x >> i) & 1) == 1) {
				V.push_back(v[i]);
			}
		}
		res.push_back(V);
	}
	return res;

}

void subsets_rec(vector<char>& v, int offset, vector<char>& pref, vector<vector<char>>& res) {
	if (offset == v.size()) {
		res.push_back(pref);
	} else {
		subsets_rec(v, offset + 1, pref, res);
		pref.push_back(v[offset]);
		subsets_rec(v, offset + 1, pref, res);
		pref.pop_back();
	}
}

vector<vector<char>> subsets(vector<char>& v) {
	vector<vector<char>> res;
	vector<char> pref;
	subsets_rec(v, 0, pref, res);
	return res;
}

void combinations_rec(vector<char>& v, int k, int offset, vector<char>& pref, vector<vector<char>>& res) {
	if (k == pref.size()) {
		res.push_back(pref);
	} else if (offset < v.size()) {
		combinations_rec(v, k, offset + 1, pref, res);
		pref.push_back(v[offset]);
		combinations_rec(v, k, offset + 1, pref, res);
		pref.pop_back();
	}
}

vector<vector<char>> combinations(vector<char>& v, int k) {
	vector<vector<char>> res;
	vector<char> pref;
	combinations_rec(v, k, 0, pref, res);
	return res;
}


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

	cout << "[permutations]" << endl;
	vector<vector<char>> pp = permutations(v);
	for (auto p: pp) {
		print_vector(p);
	}
	sort(pp.begin(), pp.end());
	vector<vector<char>> expected{{'a', 'b', 'c'}, {'a', 'c', 'b'}, {'b', 'a', 'c'}, {'b', 'c', 'a'}, {'c', 'a', 'b'}, {'c', 'b', 'a'}};
	cout << (pp == expected) << " == 1" << endl;



	cout << "\n[subsets-bits]" << endl;
	pp = subsets_bits(v);
	sort(pp.begin(), pp.end());
	for (auto p: pp) {
		print_vector(p);
	}
	expected = {{}, {'a'}, {'a', 'b'}, {'a', 'b', 'c'}, {'a', 'c'}, {'b'}, {'b', 'c'}, {'c'}};
	cout << (pp == expected) << " == 1" << endl;

	cout << endl;
	cout << "\n[subsets-rec]" << endl;
	pp = subsets(v);
	sort(pp.begin(), pp.end());
	for (auto p: pp) {
		print_vector(p);
	}
	expected = {{}, {'a'}, {'a', 'b'}, {'a', 'b', 'c'}, {'a', 'c'}, {'b'}, {'b', 'c'}, {'c'}};

	cout << (pp == expected) << " == 1" << endl;


	cout << "\n[combinations]" << endl;
	pp = combinations(v, 2);
	for (auto p: pp) {
		print_vector(p);
	}
	sort(pp.begin(), pp.end());
	expected = {{'a', 'b'}, {'a', 'c'}, {'b', 'c'}};
	cout << (pp == expected) << " == 1" << endl;

	cout << endl;


}

