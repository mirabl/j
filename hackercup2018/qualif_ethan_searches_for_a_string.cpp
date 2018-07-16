// https://www.facebook.com/hackercup/problem/1153996538071503/
/*
g++ qualif_ethan_searches_for_a_string.cpp -std=c++11 -Wall
  alias b='./a.out < qualif_ethan_searches_for_a_string.in.1'
  alias a='g++ qualif_ethan_searches_for_a_string.cpp -std=c++11 -Wall'
	alias c='echo -e "1\nABACUS" | ./a.out '


*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
	int T;
	cin >> T;

/* Input begins with an integer T, the number of given strings. Then, T lines
follow. Each line contains a single string, A. */

	for (int t = 1; t <= T; t++) {

		string pattern;
		cin >> pattern;

		
		bool found_false_start = false;
		string false_lead;
		char first_char = pattern[0];

		for (int i = 1; i < int(pattern.size()); i++) {
			if (pattern[i] == first_char) {
// cout << "MATCH CHAR " << i << " " << first_char << endl;
				string left = pattern.substr(0, i);
				string right = pattern.substr(i, i);
// cout << "LEFT -" << left << "-" << ", RIGHT -" << right << "-" << endl;
				if (left.size() != right.size()) {
					continue;
				}

/*
if (right != left) {
	cout << "RIGHT != LEFT" << endl;
}
if (i == 1 && pattern.size() > 2) {
	cout << "(i == 1 && pattern.size() > 2)" << endl;
}
*/


				if (right != left
					|| (i == 1 && pattern.size() > 2)) {
					found_false_start = true;
					false_lead = left;
				}

			}
		}

/*  For the ith given string, print a line containing "Case #i: " followed by
any valid string B that will cause Ethan's algorithm to return the wrong
value, or "Impossible" if no such string exists.
*/
		cout << "Case #" << t << ": ";

		if (found_false_start) {
			cout << false_lead << pattern;
		} else {
			cout << "Impossible";
		}

		cout << endl;

	}
}