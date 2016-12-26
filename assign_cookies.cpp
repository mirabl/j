/*
455. Assign Cookies   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 9524
Total Submissions: 19655
Difficulty: Easy
Contributors: love_FDU_llp
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.

Example 1:
Input: [1,2,3], [1,1]

Output: 1

Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.
Example 2:
Input: [1,2], [1,2,3]

Output: 2

Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.

alias a='g++ -Wall -g assign_cookies.cpp && ./a.out'

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numMaxChildren(vector<int>& greed, vector<int>& cookies) {
	sort(greed.begin(), greed.end());
	sort(cookies.begin(), cookies.end());

	int i = 0;
	int j = 0;
	int num_children = 0;
	while (i < (int)greed.size() && j < (int)cookies.size()) {
		if (cookies[j] >= greed[i]) {
			num_children++;
			++i;
		}
		++j;
	}
	return num_children;
}

int main() {
	vector<int> G1;
	G1.push_back(1);
	G1.push_back(2);
	G1.push_back(3);
	vector<int> C1;
	C1.push_back(1);
	C1.push_back(1);

	cout << numMaxChildren(G1, C1) << endl;

	vector<int> G2;
	G2.push_back(1);
	G2.push_back(2);
	vector<int> C2;
	C2.push_back(1);
	C2.push_back(2);
	C2.push_back(3);
	cout << numMaxChildren(G2, C2) << endl;
}