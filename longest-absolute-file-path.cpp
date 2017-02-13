class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> current;
        current.push("");
        int len = 0;
        int current_max = 0;
        istringstream iss(input);
        string line;
        int last_level = 0;
        while (getline(iss, line)) {
            int level = 0;
            while (line[level] == '\t') {
                level++;
            }
            while (last_level >= level) {
                len -= current.top().size();
                current.pop();
                last_level--;
            }
            current.push(line.substr(level));
            len += current.top().size();
            if (count(line.begin(), line.end(), '.') > 0) {
                current_max = max(current_max, len + int(current.size()) - 1);
            }
            last_level = level;
        }
        return current_max;
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> current;
        current.push("");
        int len = 0;
        int current_max = 0;
        istringstream iss(input);
        string line;
        while (getline(iss, line)) {
            int level = count(line.begin(), line.end(), '\t');
            while (current.size() > level) {
                len -= current.top().size();
                current.pop();
            }
            current.push(line.substr(level));
            len += current.top().size();
            if (count(line.begin(), line.end(), '.') > 0) {
                current_max = max(current_max, len + int(current.size()) - 1);
            }
        }
        return current_max;
    }
};



class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> current;
        int current_max = 0;
        istringstream iss(input);
        string line;
        while (getline(iss, line)) {
            int level = count(line.begin(), line.end(), '\t');
            while (current.size() > level) {
                current.pop();
            }
            current.push((current.empty() ? 0 : current.top()) + line.substr(level).size());
            if (count(line.begin(), line.end(), '.') > 0) {
                current_max = max(current_max, current.top() + int(current.size()) - 1);
            }
        }
        return current_max;
    }
};

