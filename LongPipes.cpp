/*

https://community.topcoder.com/stat?c=problem_statement&pm=2226&rd=5851

0)	
    	
{"1.000","2.000","4.000","8.000","16.000","32.000","64.000","128.000",
 "256.000","512.000","1024.000","2048.000","4096.000","8192.000",
 "16384.000","32768.000","65536.000"}
"65535.000"
Returns: 15
You can combine 16 lengths of pipe from the above list to form the desired length (all but the last element). Connecting 16 segments requires 15 welded joints.
1)	
    	
{"0.001","0.002","0.004","0.008","0.016","0.032","0.064","0.128","0.256",
 "0.512","1.024","2.048","4.096","8.192","16.384","32.768","65.536",
 "131.072","262.144","524.288","1048.576","2097.152","4194.304","8388.608",
 "16777.216","33554.432","67108.864","134217.728","268435.456","536870.912",
 "1073741.824","2147483.648","4294967.296","8589934.592","17179869.184", 
 "34359738.368","68719476.736","137438953.472"}
"233333333.555"
Returns: 17
A larger example along the same lines.
2)	
    	
{"1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000","1000000000.000","1000000000.000",
 "1000000000.000","1000000000.000"}
 
"38000000000.000"
Returns: 37
The maximum desiredLength.
3)	
    	
{"0.002","0.002","0.004","0.008","0.016","0.032","0.064","0.128","0.256",
 "0.512","1.024","2.048","4.096","8.192","16.384","32.768","65.536",
 "131.072","262.144","524.288","1048.576","2097.152","4194.304","8388.608",
 "16777.216","33554.432","67108.864","134217.728","268435.456","536870.912",
 "1073741.824","2147483.648","4294967.296","8589934.592","17179869.184", 
 "34359738.368","68719476.736","137438953.472"}
"1000000000.001"
Returns: -1
Not possible.

alias c='g++ -Wall LongPipes.cpp -g -std=c++11'
alias a='c && ./a.out < LongPipes.0.in'

diff <(./a.out < LongPipes.0.in) LongPipes.0.out
diff <(./a.out < LongPipes.1.in) LongPipes.1.out
diff <(./a.out < LongPipes.2.in) LongPipes.2.out
diff <(./a.out < LongPipes.3.in) LongPipes.3.out

*/
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int longPipes() {
	double x;
	vector<uint64_t> segments;
	while (cin >> x) {
		segments.push_back((uint64_t)(1000.0 * x));
	}
	uint64_t target = segments[segments.size() - 1];
	segments.resize(segments.size() - 1);
	int n = segments.size();

	if (n == 1) {
		if (segments[0] == target) {
			return 0;
		} else {
			return -1;
		}
	}

	map<uint64_t, int> left_sum;

	for (int bit_indicator = 0; bit_indicator < (1 << (n / 2)); ++bit_indicator) {
		int pieces = 0;
		uint64_t sum = 0;
		for (int i = 0; i < (n / 2); ++i) {
			if (((bit_indicator >> i) & 1) == 1) {
				sum += segments[i];
				pieces++;
			}
		}
		left_sum[sum] = pieces;
	}

	int k = n - (n / 2);
	int min_pieces = -1;
	for (int bit_indicator = 0; bit_indicator < (1 << k); ++bit_indicator) {
		int pieces = 0;
		uint64_t sum = 0;
		for (int i = 0; i < k; ++i) {
			if (((bit_indicator >> i) & 1) == 1) {
				sum += segments[(n / 2) + i];
				pieces++;
			}
		}
		if (left_sum.find(target - sum) != left_sum.end()) {
			pieces += left_sum[target - sum];
			if (min_pieces == -1 || pieces < min_pieces) {
				min_pieces = pieces;
			}
		}
	}
	if (min_pieces == -1) {
		return -1;
	} else {
		return min_pieces - 1;
	}
}

int main() {
	cout << longPipes() << endl;
	return 0;
}