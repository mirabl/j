/*


401. Binary Watch   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 16208
Total Submissions: 37476
Difficulty: Easy
Contributors: Admin
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02"


alias a='g++ binary_watch.cpp -Wall -g && ./a.out'
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int hamming(int x) {
	int w = 0;
	for (int i = 0; i < 32; ++i) {
		w += (x >> i) & 1;
	}
	return w;
}

vector<string> readBinaryWatch(int num) {
	vector<string> res;
	for (int hour = 0; hour < 12; ++hour) {
		int hamming_weight_hour = hamming(hour);
		for (int minute = 0; minute < 60; ++minute) {
			int hamming_weight = hamming_weight_hour + hamming(minute);
			if (hamming_weight == num) {
				ostringstream oss;
				oss << hour << ":";
				if (minute < 10) {
					oss << "0";
				}
				oss << minute;
				res.push_back(oss.str());
			}
		}
	}
	return res;
}

int main() {

	vector<string> v = readBinaryWatch(1);
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << endl;
	}

}