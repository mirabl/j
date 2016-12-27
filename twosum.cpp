/*
*
* https://leetcode.com/problems/two-sum/
alias a='g++ --std=c++11 twosum.cpp && ./a.out '
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findIndexForTwoSumQuadratic(const vector<int>& array, int target_sum) {
	vector<int> index;

	int n = array.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (array[i] + array[j] == target_sum) {
				index.push_back(i);
				index.push_back(j);
				return index;
			}
		}
	}

	return index;
}


vector<int> twoSum(const vector<int>& array, int target_sum) {
	vector<int> index;
	unordered_map<int, int> H;
	int n = array.size();
	for (int i = 0; i < n; ++i) {
		int add = target_sum - array[i];
		if (H.find(add) != H.end()) {
			index.push_back(H[add]);
			index.push_back(i);
			return index;
		}
		H[array[i]] = i;
	}
	return index;
}



int main(void) {
	vector<int> index;

	vector<int> v1;
	v1.push_back(2);
	v1.push_back(7);
	v1.push_back(11);
	v1.push_back(15);
	int s1 = 9;

	index = twoSum(v1, s1);

	for (int i = 0; i < index.size(); ++i) {
		cout << index[i] << " " << endl;
	}
	cout << endl;

	vector<int> v2;
	v2.push_back(-1);
	v2.push_back(0);
	v2.push_back(1);
	int s2 = 0;

	index = twoSum(v2, s2);

	for (int i = 0; i < index.size(); ++i) {
		cout << index[i] << " " << endl;
	}
	cout << endl;


	vector<int> v3;
	v3.push_back(15);
	v3.push_back(1);
	v3.push_back(3);
	v3.push_back(4);
	v3.push_back(7);
	int s3 = 11;

	index = twoSum(v3, s3);

	for (int i = 0; i < index.size(); ++i) {
		cout << index[i] << " " << endl;
	}
	cout << endl;

	vector<int> v4;
	v4.push_back(15);
	v4.push_back(4);
	v4.push_back(3);
	v4.push_back(4);
	v4.push_back(7);
	int s4 = 8;

	index = twoSum(v4, s4);

	for (int i = 0; i < index.size(); ++i) {
		cout << index[i] << " " << endl;
	}
	cout << endl;

	return 0;
}