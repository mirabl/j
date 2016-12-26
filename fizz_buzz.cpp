/*
Fizz Buzz   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 29091
Total Submissions: 49973
Difficulty: Easy
Contributors: Admin
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

alias a='g++ -Wall -g fizz_buzz.cpp'

*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> fizzBuzz(int n) {
	vector<string> res;
	for (int i = 1; i < n + 1; ++i) {
		if (i % 3 == 0 && i % 5 == 0) {
			res.push_back(string("FizzBuzz"));
		} else if (i % 3 == 0) {
			res.push_back(string("Fizz"));
		} else if (i % 5 == 0) {
			res.push_back(string("Buzz"));
		} else {
			string t;
			ostringstream oss;
			oss << i;
			res.push_back(oss.str());
		}
	}
	return res;
}

int main() {
	vector<string> v = fizzBuzz(15);
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << endl;
	}
}