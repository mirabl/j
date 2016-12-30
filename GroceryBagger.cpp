#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class GroceryBagger {
public:
	int minimumBags(int strength, vector <string> itemType) {
		map<string, int> count;
		for (int i = 0; i < (int)itemType.size(); ++i) {
			count[itemType[i]]++;
		}
		int minBags = 0;
		for (map<string, int>::iterator it = count.begin();
			 it != count.end(); ++it) {
			minBags += (it->second + (strength - 1)) / strength;
		}
		return minBags;
	}
};

int main() {
	GroceryBagger x;
	cout << x.minimumBags(2, vector<string>{"DAIRY", "DAIRY", "PRODUCE", "PRODUCE", "PRODUCE", "MEAT"}) << endl;
}