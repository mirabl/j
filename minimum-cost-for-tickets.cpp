class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> C(n, 1e8);
        for (int i = 0; i < n; i++) {
          //  cout << "i=" << i << ", di=" << days[i] << endl;
            int last = i > 0 ? C[i - 1] : 0;
            C[i] = min(C[i], last + costs[0]);
           // cout << "* " << C[i] << " l+c=" << (last+costs[0]) << endl;
            
            int j = i + 1;
            while (j < n && days[j] < days[i] + 7) {
                C[j] = min(C[j], last + costs[1]);
               // cout << "  C" << j << " =" << C[j] << endl;
                j++;
            }
            j = i + 1;
            while (j < n && days[j] < days[i] + 30) {
                C[j] = min(C[j], last + costs[2]);
                //cout << "  C" << j << " =" << C[j] << endl;

                j++;
            }
            
        }
        
        return C[n - 1];
    }
};
