/*
https://leetcode.com/problems/top-k-frequent-elements/
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> topKFrequent(const vector<int>& nums, int k) {
	vector<int> res;
	map<int, int> F;
	for (int i = 0; i < (int)nums.size(); ++i) {
		F[nums[i]]++;
	}
	priority_queue<pair<int, int>> PQ;
	for (map<int, int>::iterator it = F.begin(); it != F.end(); ++it) {
		PQ.push(pair<int, int>(- it->second, it->first));
		// Keep queue small.
		if ((int)PQ.size() > k) {
			PQ.pop();
		}
	}

	for (int i = 0; i < k; ++i) {
		pair<int, int> p = PQ.top();
		PQ.pop();
		res.push_back(p.second);
	}
	return res;
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

int main() {
	print_vector(topKFrequent(vector<int>{1, 3, 2, 2, 1}, 2));
	cout << endl;
}
