// contest
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> S;
        set<int> P;
        int j = 0;
        for (int i = 0; i < popped.size(); ) {
       //     cout << "i=" << i << endl;
            int v = popped[i];
            if (P.count(v) == 1) {
            //    cout << "S size " << S.size() << endl;
                if (S.empty() || S.top() != v) {
                  //  cout << "false 1 " << endl;
                    return false;
                }
                S.pop();
                i++;
            } else {
                while (true) {
                    //cout << "  pushing " << pushed[j] << endl;
                    S.push(pushed[j]);
                    P.insert(pushed[j]);
                    j++;
                    
                    if (P.count(v) == 1) {
                        break;
                    }
                    if (j == pushed.size()) {
                     //   cout << "false 2" << endl;
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};
