/*
https://leetcode.com/problems/queue-reconstruction-by-height/
406. Queue Reconstruction by Height   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 12749
Total Submissions: 23530
Difficulty: Medium
Contributors: Admin
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

alias a='g++ -Wall -std=c++11 queue_reconstruction_by_height.cpp && ./a.out < queue_reconstruction_by_height.0.in'

*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print_v(vector<pair<int, int> >& sol) {
	for (int i = 0; i < (int)sol.size(); ++i) {
		cout << sol[i].first << " " << sol[i].second << ", ";
	}
}

vector<pair<int, int> > reconstructQueueRec(vector<pair<int, int> >& sol, 
										 vector<pair<int, int> >& remain) {
// cout << "in rQR. sol=";
// print_v(sol);
// cout << ", remain ";
// print_v(remain);
// cout << endl;

	if (remain.empty()) {
		return sol;
	}

	vector<pair<int, int> > complete_sol;
	for (int i = 0; i < (int)remain.size(); ++i) {
// cout << "in rQR. sol=";
// print_v(sol);
// cout << ", remain ";
// print_v(remain);
// cout << " ";
// cout << "i " << i << endl;
		int h = remain[i].first;
		int k = remain[i].second;
		int k_sol = 0;
		for (int j = 0; j < (int)sol.size(); ++j) {
			if (sol[j].first >= h) {
				k_sol++;
			}
		}
		if (k_sol == k) {
// cout << "in rQR. sol=";
// print_v(sol);
// cout << ", remain ";
// print_v(remain);
// cout << " ";
// cout << "trying [" << h << " " << k << endl;
			sol.push_back(pair<int, int>(h, k));
			remain.erase(remain.begin() + i);
			vector<pair<int, int> > sol_rec = reconstructQueueRec(sol, remain);
			if (!sol_rec.empty()) {
				return sol_rec;
			}
			remain.insert(remain.begin() + i, pair<int, int>(h, k));
			sol.pop_back();
		} else {
// cout << "in rQR. sol=";
// print_v(sol);
// cout << ", remain ";
// print_v(remain);
// cout << " ";
// cout << "not trying [" << h << " " << k << ", " << k_sol << endl;

		}
	}
	return complete_sol;
}

vector<pair<int, int> > reconstructQueue(vector<pair<int, int>>& people) {
	vector<pair<int, int> > sol;
	return reconstructQueueRec(sol, people);
}


int main() {
	int h, k;
	vector<pair<int, int> > A;
	while (cin >> h >> k) {
		A.push_back(pair<int, int>(h, k));
	}

	vector<pair<int, int> > sol;
	sol = reconstructQueue(A);

	for (int i = 0; i < (int)sol.size(); ++i) {
		cout << sol[i].first << " " << sol[i].second << endl;
	}
}