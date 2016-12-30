#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FanFailure {
public:
	vector <int> getRange(vector <int> capacities, int minCooling) {
		vector<int> v;
		sort(capacities.begin(), capacities.end());
		int total_sum = 0;

		for (int i = 0; i < (int)capacities.size(); ++i) {
			total_sum += capacities[i];
		}
		int n = (int)capacities.size();
		int i = n - 1;
		int s = capacities[i];
		int mfc = 0;
		while (i >= 0 && total_sum - s >= minCooling) {
			--i;
			s += capacities[i];
			mfc++;
		}

		i = 0;
		s = capacities[0];
		int mfs = 0;
		while (i < (int)capacities.size() && total_sum - s > minCooling) {
			++i;
			s += capacities[i];
			mfs++;
		}
		v.push_back(mfs);
		v.push_back(mfc);
		return v;
	}
};

int main() {
	FanFailure f;
	vector<int> v = f.getRange(vector<int>({1,2,3}), 2);
	cout << v[0] << " " << v[1] << endl;

	v = f.getRange(vector<int>({8,5,6,7}), 22);
	cout << v[0] << " " << v[1] << endl;

	v = f.getRange(vector<int>({676, 11, 223, 413, 823, 122, 547, 187, 28}), 1000);
	cout << v[0] << " " << v[1] << endl;

}