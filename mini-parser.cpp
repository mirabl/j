/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    string read_obj(string s) {
        int end = 0;
        if (isdigit(s[0]) || s[0] == '-') {
            end++;
            while (isdigit(s[end])) {
                end++;
            }
        } else if (s[0] == '[') {
            int level = 0;
            do {
                if (s[end] == '[') {
                    level++;
                } else if (s[end] == ']') {
                    level--;
                }
                end++;
            } while (level != 0);
        } 
        return s.substr(0, end);
    }
    
    NestedInteger deserialize(string s) {
        if (s[0] == '[') {
            s.pop_back();
            NestedInteger list;
            int offset = 1;
            while (offset < s.size()) {
                string t = read_obj(s.substr(offset));
                if (!t.empty()) {
                    list.add(deserialize(t));
                    offset += t.size();
                }
                offset++;
            }
            return ni;
        } else {
            return NestedInteger(stoi(s));
        }
    }
};