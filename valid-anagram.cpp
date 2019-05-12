/*
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

alias a='g++ -Wall -std=c++11 valid_anagram.cpp && ./a.out'
*/
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagram2(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	int freq[256] = { 0 };
	for (int i = 0; i < (int)s.size(); ++i) {
		freq[(int)s[i]]++;
		freq[(int)t[i]]--;
	}
	for (int i = 0; i < 256; ++i) {
		if (freq[i] != 0) {
			return false;
		}
	}
	return true;
}

bool isAnagram(string s, string t) {
	if (s.size() != t.size()) {
		return false;
	}
	map<char, int> M;
	for (int i = 0; i < (int)s.size(); ++i) {
		M[s[i]]++;
		M[t[i]]--;
	}
	for (map<char, int>::iterator it = M.begin(); it != M.end(); ++it) {
		if (it->second != 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cout << isAnagram("", "") << " 1" << endl;
	cout << isAnagram("a", "") << " 0" << endl;
	cout << isAnagram("a", "a") << " 1" << endl;
	cout << isAnagram("a", "ab") << " 0" << endl;
	cout << isAnagram("ba", "ab") << " 1" << endl;
	cout << isAnagram("anagram", "nagaram") << " 1" << endl;
	cout << isAnagram("rat", "car") << " 0" << endl;
}


class Solution {
public:
    void rec(string& s, int lo, int hi) {
        if (lo > hi) {
            return;
        }
        
        int iP = lo;
        int n = s.size();
        for (int i = iP + 1; i <= hi; i++) {
            if (s[i] < s[iP]) {
                swap(s[i], s[iP + 1]);
                swap(s[iP + 1], s[iP]);
                iP++;
            }
        }
        rec(s, lo, iP - 1);
        rec(s, iP + 1, hi);
    }
    
    void qs(string& s) {
        int n = s.size();
        rec(s, 0, n - 1);
    }
    
    bool isAnagram(string s, string t) {
        qs(s);
        qs(t);
        return s == t;
    }
};


/*
Lomuto’s Partition Scheme

partition(arr[], lo, hi) 
    pivot = arr[hi]
    i = lo     // place for swapping
    for j := lo to hi – 1 do
        if arr[j] <= pivot then
            swap arr[i] with arr[j]
            i = i + 1
    swap arr[i] with arr[hi]
    return i
*/


class Solution {
public:
    void rec(string& s, int lo, int hi, vector<int>& aux) {
        if (lo >= hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        rec(s, lo, mid, aux);
        rec(s, mid + 1, hi, aux);
        
        int i = lo;
        int j = mid + 1;
        while (i <= mid || j <= hi) {
            if (j > hi || (i <= mid && s[i] <= s[j])) {
                aux[i - lo + j - mid - 1] = s[i];
                i++;
            } else {
                aux[i - lo + j - mid - 1] = s[j];
                j++;
            }
        }
        for (int k = 0; k < hi - lo + 1; k++) {
            s[lo + k] = aux[k];
        }
    }
    
    void ms(string& s) {
        int n = s.size();
        vector<int> aux(n);
        rec(s, 0, n - 1, aux);
    }
    
    bool isAnagram(string s, string t) {
        ms(s);
        ms(t);
        return s == t;
    }
};

class Solution {
public:
    void rec(string& s, int lo, int hi, vector<int>& aux) {
        if (lo >= hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        rec(s, lo, mid, aux);
        rec(s, mid + 1, hi, aux);
        
        int i = lo;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= hi) {
            if (s[i] <= s[j]) {
                aux[k] = s[i];
                i++;
            } else {
                aux[k] = s[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            aux[k] = s[i];
            i++;
            k++;
        }
        while (j <= hi) {
            aux[k] = s[j];
            j++;
            k++;
        }
        
        
        for (int k = 0; k < hi - lo + 1; k++) {
            s[lo + k] = aux[k];
        }
    }
    
    void ms(string& s) {
        int n = s.size();
        vector<int> aux(n);
        rec(s, 0, n - 1, aux);
    }
    
    bool isAnagram(string s, string t) {
        ms(s);
        ms(t);
        return s == t;
    }
};


class Solution {
public:
    void ms(string& s) {
        int n = s.size();
        vector<int> aux(n);
        for (int l = 1; l < n; l *= 2) {
            for (int b = 0; b < n; b += 2 * l) {
                int loLeft = b;
                int hiLeft = min(b + l - 1, n - 1);
                int loRight = min(b + l, n - 1);
                int hiRight = min(b + 2 * l - 1, n - 1);
                int i = b;
                int j = loRight;
                int k = 0;
                while (i <= hiLeft && j <= hiRight) {
                    if (s[i] <= s[j]) {
                        aux[k] = s[i];
                        i++;
                    } else {
                        aux[k] = s[j];
                        j++;
                    }
                    k++;
                }
                while (i <= hiLeft) {
                    aux[k] = s[i];
                    i++;
                    k++;
                }
                while (j <= hiRight) {
                    aux[k] = s[j];
                    j++;
                    k++;
                }
                
                for (i = 0; i < k; i++) {
                    s[loLeft + i] = aux[i];
                }
            }
        }
    }
    
    bool isAnagram(string s, string t) {
        ms(s);
        ms(t);
        return s == t;
    }
};

class Solution {
public:
    int n;
    vector<char> H;
    
    void sink(int i) {
        int infty = 1e9;
        int l = 2 * i <= n ? H[2 * i] : infty;
        int r = (2 * i + 1) <= n ? H[2 * i + 1] : infty;
        
        if (l <= r && l < H[i]) {
            swap(H[i], H[2 * i]);
            sink(2 * i);
        } else if (r < l && r < H[i]) {
            swap(H[i], H[2 * i + 1]);
            sink(2 * i + 1);
        }
    }
    
    int extract() {
        int x = H[1];
        H[1] = H[n];
        n--;
        sink(1);
        return x;
    }
    
    void heaps(string& s) {
        n = s.size();
        H.resize(1 + n);
        
        for (int i = 0; i < n; i++) {
            H[1 + i] = s[i];
        }
        
        int p = 1;
        int l = 0;
        while (2 * p <= n) {
            p = 2 * p;
            l++;
        }
        l--;
 
        for (int h = l; h >= 0; h--) {
            int b = 1 << h;
            int e = 1 << (h + 1);
            for (int i = b; i < e; i++) {
                sink(i);
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            int x = extract();
            s[i] = x;
        }
    }
    
    bool isAnagram(string s, string t) {
        heaps(s);
        heaps(t);        
        return s == t;
    }
};

