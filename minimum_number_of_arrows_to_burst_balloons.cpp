/*
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/
struct Event {
    int type;
    int x;
    int interval;
    Event(int tt, int xx, int ii): type(tt), x(xx), interval(ii) {}
};
bool comp(Event e, Event f) {
    if (e.x != f.x) {
        return e.x < f.x;
    }
    return e.type < f.type;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        const int kStart = 0;
        const int kEnd = 1;
        vector<Event> E;
        for (int i = 0; i < int(points.size()); ++i) {
            E.push_back(Event(kStart, points[i].first, i));
            E.push_back(Event(kEnd, points[i].second, i));
        }
        sort(E.begin(), E.end(), comp);
        set<int> active;
        set<int> exploded;
        int N = 0;
        for (Event e: E) {
            if (exploded.count(e.interval) == 1) {
                continue;
            }
            if (e.type == kStart) {
                active.insert(e.interval);
            } else {
                N++;
                for (int i: active) {
                    exploded.insert(i);
                }
                active.clear();
            }
            
        }
        return N;
    }
};