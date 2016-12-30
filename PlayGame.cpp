/*
https://community.topcoder.com/stat?c=problem_statement&pm=3002&rd=5863
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class PlayGame {
public:
	int saveCreatures(vector <int> you, vector <int> computer) {
		sort(you.begin(), you.end());
		sort(computer.begin(), computer.end());
		int n = (int)you.size();
		int ypos = n - 1;
		int cpos = n - 1;

		int saved = 0;
		while (cpos >= 0) {
			if (you[ypos] > computer[cpos]) {
				saved += you[ypos];
				ypos--;
			}
			cpos--;
		}
		return saved;
	}
};

int main() {
	PlayGame p;
	cout << p.saveCreatures(vector<int>{5, 15, 100, 1, 5}, vector<int>{5, 15, 100, 1, 5}) << endl;
	cout << p.saveCreatures(vector<int>{1, 3, 5, 7, 9, 11, 13, 15, 17, 19}, vector<int>{2, 4, 6, 8, 10, 12, 14, 16, 18, 20}) << endl;
	cout << p.saveCreatures(vector<int>{651, 321, 106, 503, 227, 290, 915, 549, 660, 115, 491, 378, 495, 789, 507, 381, 685, 530, 603, 394, 7, 704, 101, 620, 859, 490, 744, 495, 379, 781, 550, 356, 950, 628, 177, 373, 132, 740, 946, 609, 29, 329, 57, 636, 132, 843, 860, 594, 718, 849}, vector<int>{16, 127, 704, 614, 218, 67, 169, 621, 340, 319, 366, 658, 798, 803, 524, 608, 794, 896, 145, 627, 401, 253, 137, 851, 67, 426, 571, 302, 546, 225, 311, 111, 804, 135, 284, 784, 890, 786, 740, 612, 360, 852, 228, 859, 229, 249, 540, 979, 55, 82}) << endl;

}