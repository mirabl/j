class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> M;
        for (string dirstring: paths) {
            string path = "";
            int i = 0;
            while (i < dirstring.size() && dirstring[i] != ' ') {
                path += dirstring[i];
                i++;
            }
            i++;
            while (i < dirstring.size()) {
                string filename;
                while (dirstring[i] != '(') {
                    filename += dirstring[i];
                    i++;
                }
                i++;
                string content;
                while (dirstring[i] != ')') {
                    content += dirstring[i];
                    i++;
                }
                i += 2;
                M[content].push_back(path + "/" + filename);
            }
        }
        
        vector<vector<string>> res;
        for (pair<string, vector<string>> kv: M) {
            if (kv.second.size() > 1) {
                res.push_back(kv.second);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> M;
        for (string dirstring: paths) {
            istringstream iss(dirstring);
            string path;
            iss >> path;
            string s;
            while (iss >> s) {
                int j = s.find('(');
                int k = s.find(')');
                string filename = s.substr(0, j);
                string content = s.substr(j + 1, k - j - 1);
                M[content].push_back(path + "/" + filename);
            }
        }

        vector<vector<string>> res;
        for (pair<string, vector<string>> kv: M) {
            if (kv.second.size() > 1) {
                res.push_back(kv.second);
            }
        }
        return res;
    }
};

