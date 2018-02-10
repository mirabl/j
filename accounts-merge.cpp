class Solution {
public:
    string find(string a, map<string, string>& parent) {
        if (parent[a] == a) {
            return a;
        }
        return find(parent[a], parent);
    }
    
    void do_union(string a, string b, map<string, string>& parent) {
        parent[find(b, parent)] = find(a, parent);
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> parent;
        map<string, string> name_by_mail;
        for (auto v: accounts) {
            for (int i = 1; i < v.size(); i++) {
                parent[v[i]] = v[i];
                name_by_mail[v[i]] = v[0];
            }
        }
            
        for (auto v: accounts) {
            for (int i = 2; i < v.size(); i++) {
                do_union(v[1], v[i], parent);
            }
        }

        map<string, vector<string>> emailsByParent;
        for (auto kv: parent) {
            emailsByParent[find(kv.second, parent)].push_back(kv.first);
        }
        
        vector<vector<string>> res;
        for (auto kv: emailsByParent) {
            vector<string> emails(kv.second);
            sort(emails.begin(), emails.end());

            vector<string> row{name_by_mail[kv.first]};
            row.insert(row.end(), emails.begin(), emails.end());
            res.push_back(row);
        }
        return res;
    }
};

// To clean