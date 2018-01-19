class MyCalendar {
private:
    vector<pair<int, int>> _times;
    
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if (_times.empty() || end <= _times.front().first) {
            _times.insert(_times.begin(), {start, end});
            return true;
        }
        for (int i = 0; i < _times.size(); i++) {
            if (start >= _times[i].second && (i == _times.size() - 1 || end <= _times[i + 1].first)) {
                _times.insert(_times.begin() + i + 1, {start, end});
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
 class MyCalendar {
private:
    vector<pair<int, int>> _times{{-1, -1}, {1e9 + 1, 1e9 + 1}};
    
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (int i = 0; i < _times.size() - 1; i++) {
            if (start >= _times[i].second && end <= _times[i + 1].first) {
                _times.insert(_times.begin() + i + 1, {start, end});
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

 class MyCalendar {
private:
    list<pair<int, int>> _times{{-1, -1}, {1e9 + 1, 1e9 + 1}};
    
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for (auto it = _times.begin(); next(it) != _times.end(); it++) {
            if (start >= (*it).second && end <= (*next(it)).first) {
                _times.insert(next(it), {start, end});
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */