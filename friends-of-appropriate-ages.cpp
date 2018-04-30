// contest
class Solution {
public:
    bool possible(int A, int B) {
        return !(B <= 0.5 * double(A) + 7 || B > A || (B > 100 & A < 100));
    }
    
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        map<int, int> F;
        for (int age: ages) {
            F[age]++;
        }
        for (int age = 1; age <= 120; age++) {
            if (F[age] == 0) {
                continue;
            }
            for (int o = 1; o <= age; o++) {
                if (possible(age, o)) {
                    int d;
                    if (age == o) {
                        d = F[o] - 1;
                    } else {
                        d = F[o];
                    }
                    //cout << "ans += " << F[age] << " " << o << endl;
                    ans += F[age] * d;
                }
            }
        }
        return ans;
    }
};
