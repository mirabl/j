/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
Letter Combinations of a Phone Number QuestionEditorial Solution  My Submissions
Given a digit string, return all possible letter combinations that the number could represent.
alias a='g++ -g letter_combinations_of_phone_number.cpp -Wall && ./a.out'


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
2abc3def4ghi5jkl6mno7pqrs8tuv9wxyz

*/


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> letterCombinationsRec(const string& num, map<char, vector<string> >& digitToLetter, const string& prefix)
{
	vector<string> r;

	if (num.empty()) {
		r.push_back(prefix);
		return r;
	}

	vector<string> v = digitToLetter[num[0]];
	string num_tail;
 	num_tail = num.substr(1, num.size() - 1);

	for (int i = 0; i < (int)v.size(); ++i) {
		vector<string> r_temp = letterCombinationsRec(num_tail, digitToLetter, prefix + v[i]);
		for (int j = 0; j < (int)r_temp.size(); ++j) {
			r.push_back(r_temp[j]);
		}

	}

	return r;
}

vector<string> letterCombinations(const string& num) {
	map<char, vector<string> > digitToLetter;
	vector<string> strings2;
	strings2.push_back("a");
	strings2.push_back("b");
	strings2.push_back("c");
	digitToLetter['2'] = strings2;

	vector<string> strings3;
	strings3.push_back("d");
	strings3.push_back("e");
	strings3.push_back("f");
	digitToLetter['3'] = strings3;

	vector<string> strings4;
	strings4.push_back("g");
	strings4.push_back("h");
	strings4.push_back("i");
	digitToLetter['4'] = strings4;

	vector<string> strings5;
	strings5.push_back("j");
	strings5.push_back("k");
	strings5.push_back("l");
	digitToLetter['5'] = strings5;

	vector<string> strings6;
	strings6.push_back("m");
	strings6.push_back("n");
	strings6.push_back("o");
	digitToLetter['6'] = strings6;

	vector<string> strings7;
	strings7.push_back("p");
	strings7.push_back("q");
	strings7.push_back("r");
	strings7.push_back("s");
	digitToLetter['7'] = strings7;

	vector<string> strings8;
	strings8.push_back("t");
	strings8.push_back("u");
	strings8.push_back("v");
	digitToLetter['8'] = strings8;

	vector<string> strings9;
	strings9.push_back("x");
	strings9.push_back("y");
	strings9.push_back("z");
	digitToLetter['9'] = strings9;


	return letterCombinationsRec(num, digitToLetter, "");
}

int main() {
	vector<string> r = letterCombinations("234");
	for (int i = 0; i < (int)r.size(); ++i) {
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}


class Solution {
public:
    map<char, string> M;

    void rec(string& digits, int offset, string& pref, vector<string>& res) {
        if (offset == digits.size()) {
            res.push_back(pref);
        } else {
            for (char c: M[digits[offset]]) {
                pref.push_back(c);
                rec(digits, offset + 1, pref, res);
                pref.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string pref;
        M['2'] = "abc"; M['3'] = "def"; M['4'] = "ghi"; M['5'] = "jkl"; M['6'] = "mno"; M['7'] = "pqrs"; M['8'] = "tuv"; M['9'] = "wxyz";
        rec(digits, 0, pref, res);
        return res;
    }
};


class Solution {
public:
    map<char, string> M{{'2', "abc" }, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void rec(string& digits, int offset, string& pref, vector<string>& res) {
        if (offset == digits.size()) {
            res.push_back(pref);
        } else {
            for (char c: M[digits[offset]]) {
                pref.push_back(c);
                rec(digits, offset + 1, pref, res);
                pref.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string pref;
        rec(digits, 0, pref, res);
        return res;
    }
};