/*
https://leetcode.com/problems/rectangle-area/
223. Rectangle Area   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 54473
Total Submissions: 171212
Difficulty: Easy
Contributors: Admin
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/
// Generic solution for n rectangles.
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

enum { OPEN = 0, CLOSE = 1};

struct IntervalEvent {
	int type;
	int x;
	IntervalEvent(int xx, int t): type(t), x(xx) { }
};

bool compareIntervalEvents(IntervalEvent a, IntervalEvent b) {
	if (a.x == b.x) {
		return a.type < b.type;
	} else {
	 	return a.x < b.x;
	}
}

int heightOfUnionOfIntervals(map<pair<int, int>, int>& active_intervals) {
	vector<IntervalEvent> events;
	for (map<pair<int, int>, int>::iterator it = active_intervals.begin();
		 it != active_intervals.end(); ++it) {
		if (it->second > 0) {
			events.push_back(IntervalEvent(it->first.first, OPEN));
			events.push_back(IntervalEvent(it->first.second, CLOSE));
		}
	}
	if (events.empty()) {
		return 0;
	}
	sort(events.begin(), events.end(), compareIntervalEvents);
	int total_length = 0;
	int num_active = 0;
	int last_x = events[0].x; // first x.
	for (vector<IntervalEvent>::iterator it = events.begin(); 
		 it != events.end(); ++it) {
		int x = it->x;
		if (num_active > 0) {
			total_length += x - last_x;
		}
		if (it->type == OPEN) {
			num_active++;
		} else {
			num_active--;
		}
		last_x = x;
	}
	return total_length;
}

struct RectangleEvent {
	int left;
	int type;
	int bottom;
	int top;
	RectangleEvent(int l, int t, int b, int tt): left(l), type(t), bottom(b), top(tt) { }
};

bool compareRectangleEvents(RectangleEvent a, RectangleEvent b) {
	if (a.left == b.left) {
		return a.type < b.type;
	} else {
	 	return a.left < b.left;
	}
}

int computeArea2(int A, int B, int C, int D, int E, int F, int G, int H) {
	vector<RectangleEvent> events = { RectangleEvent(A, OPEN, B, D), 
									    RectangleEvent(C, CLOSE, B, D),
								        RectangleEvent(E, OPEN, F, H), 
								        RectangleEvent(G, CLOSE, F, H)};
    sort(events.begin(), events.end(), compareRectangleEvents);
    map<pair<int, int>, int> active_intervals;
    int last_x = events[0].left;
    int area = 0;
    for (int i = 0; i < (int)events.size(); ++i) {
    	int x = events[i].left;
    	int height = heightOfUnionOfIntervals(active_intervals);
    	area += (x - last_x) * height;

    	pair<int, int> interval = pair<int, int>(events[i].bottom, events[i].top);
    	if (events[i].type == OPEN) {
    		active_intervals[interval]++;
    	} else {
    		active_intervals[interval]--;
    	}
    	last_x = x;
    }
	return area;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int cum = (C - A) * (D - B) + (G - E) * (H - F);
	int inter = 0;
	if (E >= C || A >= G || F >= D || B >= H) {
		inter = 0;
	} else {
		inter = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
	}
	return cum - inter;
}


int main() {
	cout << computeArea(0, 0, 0, 0, 4, 4, 4, 4) << " 0" << endl;
	cout << computeArea(0, 0, 0, 1, 0, 0, 0, 0) << " 0" << endl;
	cout << computeArea(0, 0, 1, 1, 2, 0, 3, 1) << " 2" << endl;
	cout << computeArea(0, 0, 0, 1, 1, 0, 2, 1) << " 1" << endl;
	cout << computeArea(0, 0, 2, 2, 0, 0, 1, 1) << " 4" << endl;
	cout << computeArea(0, 0, 1, 1, 0, 0, 2, 2) << " 4" << endl;
	cout << computeArea(0, 0, 2, 2, 1, 1, 3, 3) << " 7" << endl;
	cout << computeArea(-2, -2, 2, 2, -4, 3, -3, 4) << " 17" << endl;
	cout << computeArea(-2, -2, 2, 2, -1, 4, 1, 6) << " 20" << endl;
	cout << endl;
}

