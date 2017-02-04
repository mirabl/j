class Solution {
public:
vector<pair<int, int> > reconstructQueue(vector<pair<int, int>>& people) {
	vector<pair<int, int> > sol;
    vector<pair<int, int>> P(people);
    const int n = int(people.size());
    for (int i = 0; i < n; i++) {
        int min_i = -1;
        for (int j = 0; j < n; j++) {
            if (P[j].second == 0 && (min_i == -1 || P[j].first < P[min_i].first)) {
                min_i = j;
            }
        }
        sol.push_back(people[min_i]);
        for (int j = 0; j < n; j++) {
            if (P[j].first <= P[min_i].first) {
                P[j].second--;
            }
        }
    }
    return sol;
    }
};