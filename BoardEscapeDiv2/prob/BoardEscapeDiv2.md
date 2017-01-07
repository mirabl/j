# [BoardEscapeDiv2](/tc?module=ProblemDetail&rd=16626&pm=13299)
*Single Round Match 676 Round 1 - Division II, Level Two*

## Statement
Alice and Bob have a rectangular board divided into a grid with r rows and c columns.
The grid is described by the String[] *s*.
Each character of *s* represents one cell.
There are four types of cells:

'E' denotes an exit. There may be arbitrarily many exits, possibly zero.
'T' means the square contains a single token. Initially there will be exactly one token on the entire board.
'#' denotes an obstacle.
'.' denotes an empty cell.

Alice and Bob will play a game on this board.
The game is parameterized by the int *k*.
The token initially has the number *k* on it.
The players will take alternating turns, starting with Alice.
A player's turn consists of the following steps:

The player moves the token one square up, down, left, or right. The token cannot go over the edge of the board and it cannot enter a cell with an obstacle.
If this token is on an exit, it disappears from the board.
Otherwise, subtract one from the number on the token. If the number on the token is zero, remove it from the board.

The first player unable to make a move loses the game.
(This happens when the token is stuck and also when it already left the board.)

You are given the String[] *s* and the int *k*
Compute the winner of the game, assuming both Alice and Bob play optimally.
Return the winner's name: either "Alice" or "Bob".
Note that the return value is case-sensitive.

## Definitions
- *Class*: `BoardEscapeDiv2`
- *Method*: `findWinner`
- *Parameters*: `String[], int`
- *Returns*: `String`
- *Method signature*: `String findWinner(String[] s, int k)`

## Constraints
- r,c will be between 1 and 50, inclusive.
- *s* will contain exactly r elements, each consisting of c characters.
- Each character of each element of *s* will be one of 'T', 'E', '#', or '.'.
- There will be exactly 1 'T' charcters within all elements of *s*.
- *k* will be between 1 and 100, inclusive.

## Examples
### Example 1
#### Input
<c>["T.#",<br /> "#.E"],<br />3</c>
#### Output
<c>"Alice"</c>
#### Reason
The token starts in row 0, column 0.
At the beginning of the game the number on the token is 3.
In her first move Alice must push the token to the right and decrease the number to 2.
Bob can then move the token either left (back where it started) or down.
Either way, after Bob's move the number on the token will be 1.
Regardless of which option Bob chose, Alice can always make the token disappear in her second move:
either she reaches the exit, or the token disappears on its own after its counter reaches zero.
Afterwards Bob cannot make his second move and therefore Alice wins the game.

### Example 2
#### Input
<c>["E#E",<br /> "#T#",<br /> "E#E"],<br />99</c>
#### Output
<c>"Bob"</c>
#### Reason
As the token is stuck between obstacles, Alice has no valid move to make and therefore she immediately loses the game.

### Example 3
#### Input
<c>["#E...",<br /> "#...E",<br /> "E.T#.",<br /> "..#.."],<br />13</c>
#### Output
<c>"Alice"</c>
### Example 4
#### Input
<c>["TE"],<br />50</c>
#### Output
<c>"Alice"</c>
### Example 5
#### Input
<c>[".T."],<br />1</c>
#### Output
<c>"Alice"</c>
### Example 6
#### Input
<c>["..........................",<br /> "......EEE..EEE..E...E.....",<br /> ".....E.....E..E.EE.EE.....",<br /> "......EEE..EEE..E.E.E.....",<br /> ".........E.E.E..E...E.....",<br /> "......EEE..E..E.E...E.....",<br /> "..........................",<br /> "...E#E#E#E#E#E#E#E#E#E#...",<br /> "..........................",<br /> "......EEE..EEE...EEE......",<br /> ".....E........E.E.........",<br /> "......EEE.....E..EEE......",<br /> ".....E...E...E..E...E.....",<br /> "......EEE....E...EEE......",<br /> "..........................",<br /> "...#E#E#E#E#E#E#E#E#E#E...",<br /> "..........................",<br /> "....EE...E...E..E.EEE.E...",<br /> "...E.....E...E..E.E...E...",<br /> "...E.EE..E...EEEE.EE..E...",<br /> "...E..E..E...E..E.E.......",<br /> "....EE...EEE.E..E.E...E...",<br /> "T........................."],<br />100</c>
#### Output
<c>"Bob"</c>

