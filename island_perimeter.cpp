/*
https://leetcode.com/problems/island-perimeter/

Island Perimeter   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 13471
Total Submissions: 23874
Difficulty: Easy
Contributors: amankaraj
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:

alias a='g++ -g -Wall island_perimeter.cpp && ./a.out'
*/
#include <iostream>
#include <vector>

using namespace std;


int perimeter(vector<vector<int> >& grid) {
	const int LAND = 1;
	const int WATER = 0;

	int num_rows = grid.size();
	if (num_rows == 0) {
		return 0;
	}
	int num_cols = grid[0].size();
	int transitions = 0;

	for (int row = 0; row < num_rows; ++row) {
		bool in_land = false;
		for (int col = 0; col < num_cols; ++col) {
			if (!in_land && grid[row][col] == LAND) {
				transitions++;
			}
			in_land = (grid[row][col] == LAND);
		}
	}
	for (int col = 0; col < num_cols; ++col) {
		bool in_land = false;
		for (int row = 0; row < num_rows; ++row) {
			if (!in_land && grid[row][col] == LAND) {
				transitions++;
			}
			in_land = (grid[row][col] == LAND);
		}
	}
	return 2*transitions;
}

int main() {

	vector<vector<int> > grid;
	vector<int> row1;
	row1.push_back(0);
	row1.push_back(1);
	row1.push_back(0);
	row1.push_back(0);
	grid.push_back(row1);

	vector<int> row2;
	row2.push_back(1);
	row2.push_back(1);
	row2.push_back(1);
	row2.push_back(0);
	grid.push_back(row2);

	vector<int> row3;
	row3.push_back(0);
	row3.push_back(1);
	row3.push_back(0);
	row3.push_back(0);
	grid.push_back(row3);

	vector<int> row4;
	row4.push_back(1);
	row4.push_back(1);
	row4.push_back(0);
	row4.push_back(0);
	grid.push_back(row4);

	cout << perimeter(grid) << endl;
}