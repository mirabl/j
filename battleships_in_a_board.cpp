/*
https://leetcode.com/problems/battleships-in-a-board/

Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.

alias a='g++ -Wall -std=c++11 -g battleships_in_a_board.cpp && ./a.out < battleships_in_a_board.0.in'

for i in 0 1 2 3 4 5 6;
do
diff <(./a.out < battleships_in_a_board.$i.in) battleships_in_a_board.$i.out
done

*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void removeBattleShip(vector<vector<char> >& board, int start_row, int start_col) {
	int n_rows = (int)board.size();
	int n_cols = (int)board[0].size();

	// S
	int row = start_row + 1;
	int col = start_col;
	while (row < n_rows && col < n_cols && board[row][col] == 'X') {
		board[row][col] = '.';
		row++;
	}
	// E
	row = start_row;
	col = start_col + 1;
	while (row < n_rows && col < n_cols && board[row][col] == 'X') {
		board[row][col] = '.';
		col++;
	}
}

int countBattleships(vector<vector<char> >& board) {
	int n_rows = (int)board.size();
	if (n_rows == 0) {
		return 0;
	}
	int n_cols = (int)board[0].size();
	if (n_cols == 0) {
		return 0;
	}

	int num_ships = 0;
	for (int row = 0; row < n_rows; ++row) {
		for (int col = 0; col < n_cols; ++col) {
			if (board[row][col] == 'X') {
				removeBattleShip(board, row, col);
				num_ships++;
			}
		}
	}
	return num_ships;
}


int main() {
	vector<vector<char> > board;

	string s;
	while (cin >> s) {
		vector<char> r;
		for (int col = 0; col < (int)s.size(); ++col) {
			r.push_back(s[col]);
		}
		board.push_back(r);
	}

	cout << countBattleships(board) << endl;
}