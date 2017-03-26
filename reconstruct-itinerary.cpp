class Solution {
public:
    bool dfs(vector<vector<int>>& G, int num_tickets, int from, vector<string>& airports, vector<string>& route) {
        if (route.size() == num_tickets + 1) {
            return true;
        }
        
        for (int i = 0; i < G.size(); i++) {
            if (G[from][i] > 0) {
                G[from][i]--;
                route.push_back(airports[i]);
                if (dfs(G, num_tickets, i, airports, route)) {
                    return true;
                }
                route.pop_back();
                G[from][i]++;
            }
        }
        return false;
    }


    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        set<string> airportsSet;
        for (auto ticket: tickets) {
            airportsSet.insert(ticket.first);
            airportsSet.insert(ticket.second);
        }
        vector<string> airports(airportsSet.begin(), airportsSet.end());
        sort(airports.begin(), airports.end());
        map<string, int> airportsIndex;
        for (int i = 0; i < airports.size(); i++) {
            airportsIndex[airports[i]] = i;
        }
        int n = airports.size();
        int num_tickets = tickets.size();
        
        vector<vector<int>> G(n, vector<int>(n, 0));
        for (auto ticket: tickets) {
            G[airportsIndex[ticket.first]][airportsIndex[ticket.second]]++;
        }
        
        vector<string> res;
        res.push_back("JFK");
        dfs(G, num_tickets, airportsIndex["JFK"], airports, res);
        return res;
    }
};

class Solution {
public:
    bool dfs(vector<pair<string, string>>& tickets, const string& from, vector<string>& route) {
        if (route.size() == tickets.size() + 1) {
            return true;
        }
        
        for (int i = 0; i < tickets.size(); i++) {  // Inefficient.
            if (tickets[i].first == from) {
                route.push_back(tickets[i].second);
                auto tmp = tickets[i].first;
                tickets[i].first = "";
                if (dfs(tickets, tickets[i].second, route)) {
                    return true;
                }
                tickets[i].first = tmp;
                route.pop_back();
            }
        }
        return false;
    }


    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        sort(tickets.begin(), tickets.end());

        vector<string> route{"JFK"};
        dfs(tickets, "JFK", route);
        return route;
    }
};
