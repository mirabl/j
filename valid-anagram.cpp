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




class Solution {
public:
    void qs(string& s, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        
        int j = lo;
        for (int i = lo; i < hi; i++) {
            if (s[i] < s[hi]) {
                swap(s[i], s[j]);
                j++;
            }
        }
        
        swap(s[hi], s[j]);
        qs(s, lo, j - 1);
        qs(s, j + 1, hi);
    }
    
    void sort(string& s) {
        int n = s.size();
        qs(s, 0, n - 1);
    }
    
    bool isAnagram(string s, string t) {
        sort(s);
        sort(t);
        return s == t;
    }
};


class Solution {
public:
    void sort(string& s, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        
        int firstGreater = lo;
        for (int i = lo; i < hi; i++) {
            if (s[i] <= s[hi]) {
                swap(s[i], s[firstGreater]);
                firstGreater++;
            }
        }
        swap(s[hi], s[firstGreater]);
        sort(s, lo, firstGreater - 1);
        sort(s, firstGreater, hi);
        
    }
    
    bool isAnagram(string s, string t) {
        sort(s, 0, s.size() - 1);
        cout << s << endl;
        sort(t, 0, t.size() - 1);
        cout << t << endl;
        return s == t;
    }
};

class Solution {
public:
    void sort(string& s, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        
        int firstGreater = lo;
        for (int i = lo; i < hi; i++) {
            if (s[i] < s[hi]) {
                swap(s[i], s[firstGreater]);
                firstGreater++;
            }
        }
        swap(s[hi], s[firstGreater]);
        sort(s, lo, firstGreater - 1);
        sort(s, firstGreater + 1, hi);
        
    }
    
    bool isAnagram(string s, string t) {
        sort(s, 0, s.size() - 1);
        cout << s << endl;
        sort(t, 0, t.size() - 1);
        cout << t << endl;
        return s == t;
    }
};


class Heap {
public:
    int N;
    vector<char> T;
    Heap() {
        T.resize(1 << 16);
        N = 0;
    }
    
    void add(char c) {
        N++;
        T[N - 1] = c;
        bubbleUp(N - 1);
    }
    
    void bubbleUp(int x) {
        if (x == 0) {
            return;
        }
        int p = x / 2;
        if (T[p] < T[x]) {
            swap(T[p], T[x]);
            bubbleUp(p);
        }
    }
    
    void sinkDown(int x) {
        if (2 * x >= N - 1) {
            return;
        }
        int iMax = T[2*x] > T[2*x + 1] ? 2*x : 2*x + 1;
        if (T[iMax] > T[x]) {
            swap(T[iMax], T[x]);
            sinkDown(iMax);
        }
    }
    
    void extractMax() {
        swap(T[0], T[N - 1]);
        N--;
        sinkDown(0);
    }
    
    bool empty() {
        return N > 0;
    }
    
    string getString(int M) {
        return string(T.begin(), T.begin() + M);
    } 
};

class Solution {
public:
    void xsort(string& s) {
        Heap H;
        for (auto c: s) {
            H.add(c);
        }
        for (int i = 0; i < s.size(); i++) {
            H.extractMax();
        }
        s = H.getString(s.size());
    }
    
    bool isAnagram(string s, string t) {
        xsort(s);
        sort(t.begin(), t.end());
        return s == t;
    }
};

// MS
class Solution {
public:
    string A;
    
    void ms(string& s, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int mid = (hi + lo) / 2;
        ms(s, lo, mid);
        ms(s, mid + 1, hi);
        
        int i = lo;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= hi) {
            if (s[i] <= s[j]) {
                A[k] = s[i];
                i++;
            } else {
                A[k] = s[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            A[k] = s[i];
            i++;
            k++;
        }
        while (j <= hi) {
            A[k] = s[j];
            j++;
            k++;
        }
        
        for (int i = lo; i <= hi; i++) {
            s[i] = A[i - lo];
        }
        
    }
    
    bool isAnagram(string s, string t) {
        A.resize(s.size());
        ms(s, 0, int(s.size()) - 1);
        sort(t.begin(), t.end());
        return s == t;
    }
};

class Solution {
public:
    void qs(string& s, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int firstGreater = lo;
        
        int i = lo;
        while (i < hi) {
            if (s[i] >= s[hi]) {
                i++;
                
            } else {
                swap(s[i], s[firstGreater]);
                firstGreater++;
                i++;
            }
        }
        
        swap(s[hi], s[firstGreater]);
        qs(s, lo, firstGreater - 1);
        qs(s, firstGreater + 1, hi);
    }
    
    bool isAnagram(string s, string t) {
        qs(s, 0, int(s.size()) - 1);
        qs(t, 0, int(t.size()) - 1);
        
        return s == t;
    }
};

class Solution {
public:
    void r(string& s, int lo, int hi, vector<char>& aux) {
        if (lo >= hi) {
            return;
        }
        
        int mid = lo + (hi - lo) / 2;
        r(s, lo, mid, aux);
        r(s, mid + 1, hi, aux);
        
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
        
        for (int i = lo; i <= hi; i++) {
            s[i] = aux[i - lo];
        }
        
    }
    
    void ms(string& s) {
        int n = s.size();
        vector<char> aux(n);
        r(s, 0, n - 1, aux);
    }
    
    bool isAnagram(string s, string t) {
        ms(s);
        ms(t);
        
        return s == t;
    }
};
