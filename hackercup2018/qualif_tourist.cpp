// https://www.facebook.com/hackercup/problem/1632703893518337/
/*
g++ qualif_tourist.cpp -std=c++11 -Wall
 alias b='./a.out < qualif_tourist.in.1'
 alias a='g++ qualif_tourist.cpp -std=c++11 -Wall'

*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		long long N, K, V;
		cin >> N >> K >> V;
		vector<string> attractions;
		for (int n = 0; n < N; n++) {
			string s;
			cin >> s;
			attractions.push_back(s);
		}
/*
cout << "testcase " << t << endl;
cout << "N=" << N << " K=" << K << " V=" << V << endl;
for (string attraction: attractions) {
	cout << "\t-" << attraction << "-" << endl;
}

cout << endl << endl;
*/
		cout << "Case #" << (t + 1) << ":";
		int start = (((V - 1) % N) * K) % N;
		// cout << "start= "" << start << endl;

		vector<int> idx;
		for (int i = 0; i < K; i++) {
			idx.push_back((start + i) % N);
		}
		sort(idx.begin(), idx.end());

/*
cout << "idx:";
for (int z: idx) {
	cout << " " << z;
}
cout << endl;
*/
		for (int i: idx) {
			cout << " " << attractions[i];
		}

		cout << endl;
	}
}