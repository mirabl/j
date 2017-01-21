# [PathGameDiv2](/tc?module=ProblemDetail&rd=16080&pm=13506)
*Single Round Match 637 Round 1 - Division II, Level Two*

## Statement
Cat Snuke is playing the Path Game.

The Path Game is played on a rectangular grid of square cells.
The grid has 2 rows and some positive number of columns.
Each cell is either black or white.

A left-to-right path in the grid is a sequence of white cells such that the first cell in the sequence is in the leftmost column, the last cell in the sequence is in the rightmost column, and each pair of consecutive cells shares a common side.

The initial coloring of the grid is such that there is at least one left-to-right path.
You are given this initial coloring as a String[] *board* with two elements.
For each i and j, *board*[i][j] is either '#' (representing a black cell) or '.' (representing a white cell).

Snuke may color some of the white cells black.
After he does so, there must still be at least one left-to-right path left on the board.
The goal of the game is to color as many cells black as possible.
Compute and return the largest number of cells Snuke can color black.
(Note that the cells that are already black do not count.)

## Definitions
- *Class*: `PathGameDiv2`
- *Method*: `calc`
- *Parameters*: `String[]`
- *Returns*: `int`
- *Method signature*: `int calc(String[] board)`

## Constraints
- *board* will contain 2 elements.
- Each element in *board* will contain between 1 and 50 characters, inclusive.
- All elements in *board* will have the same length.
- Each character in *board* will be '#' or '.'.
- The grid described by *board* will contain a left-to-right path.

## Examples
### Example 1
#### Input
<c>["#...."<br />,"...#."]</c>
#### Output
<c>2</c>
#### Reason
Snuke can color at most two white cells black.
One possible final state of the board looks as follows:
#....
..###

### Example 2
#### Input
<c>["#"<br />,"."]</c>
#### Output
<c>0</c>
#### Reason
Snuke can't color any cells.

### Example 3
#### Input
<c>["."<br />,"."]</c>
#### Output
<c>1</c>
### Example 4
#### Input
<c>["....#.##.....#..........."<br />,"..#......#.......#..#...."]</c>
#### Output
<c>13</c>

