// contest
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> subDomainsCount;
        for (auto cpdomain: cpdomains) {
            istringstream iss(cpdomain);
            int count;
            string domain;
            iss >> count >> domain;
            
            domain.insert(domain.begin(), '.');
            string token;
            while (!domain.empty()) {
                if (domain[0] == '.') {
                    domain.erase(domain.begin());
                    if (!domain.empty()) {
                        subDomainsCount[domain] += count;
                    }
                }
                domain.erase(domain.begin());
            }            
        }
        vector<string> res;
        for (auto kvp: subDomainsCount) {
            ostringstream oss;
            oss << kvp.second << " " << kvp.first;
            res.push_back(oss.str());
        }
        
        return res;
    }
};