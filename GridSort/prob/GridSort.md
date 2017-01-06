# [GridSort](/tc?module=ProblemDetail&rd=16832&pm=14442)
*Single Round Match 702 Sponsored By BAH Round 1 - Division II, Level Two*

## Statement
Charlie has a grid of *n* rows by *m* columns.
The rows are numbered 0 through *n*-1 from top to bottom.
The columns are numbered 0 through *m*-1 from left to right.

Each cell of the grid contains a positive integer.
The integers in Charlie's grid are a permutation of the numbers 1 through *n***m*.
(I.e., each of these numbers occurs in the grid exactly once.)

Given a grid, its value list is a sequence constructed by listing all values in the grid in row major order.
That is, we first list the values in row 0 from left to right, then the values in row 1 from left to right, and so on.

You are given the ints *n* and *m*: the dimensions of Charlie's grid.
You are also given a int[] *grid*: the value list for Charlie's grid.
(Formally, *grid*[i**m*+j] is the value stored in row i, column j of the grid.)

Charlie can modify his grid in two ways: He may swap any two rows, and he may swap any two columns.
Charlie now wonders whether there is a sequence of swaps that would sort his grid - that is, rearrange its elements in such a way that the value list of the new grid will be the ordered sequence (1,2,3,...,*n***m*).

If it is possible to sort Charlie's grid, return "Possible". Otherwise, return "Impossible".

## Definitions
- *Class*: `GridSort`
- *Method*: `sort`
- *Parameters*: `int, int, int[]`
- *Returns*: `String`
- *Method signature*: `String sort(int n, int m, int[] grid)`

## Constraints
- n,m will be between 1 and 50, inclusive.
- *grid* will be a permutation of [1,...,*n***m*].

## Examples
### Example 1
#### Input
<c>2,<br />2,<br />[<br /> 1,2,<br /> 3,4<br />]</c>
#### Output
<c>"Possible"</c>
#### Reason
This grid is already sorted, so Charlie doesn't need to do anything.

### Example 2
#### Input
<c>2,<br />2,<br />[<br /> 3,4,<br /> 1,2<br />]</c>
#### Output
<c>"Possible"</c>
#### Reason
Charlie can sort this grid by swapping rows 0 and 1.

### Example 3
#### Input
<c>2,<br />2,<br />[<br /> 4,3,<br /> 1,2<br />]</c>
#### Output
<c>"Impossible"</c>
### Example 4
#### Input
<c>1,<br />10,<br />[4,5,1,2,9,8,3,10,7,6]</c>
#### Output
<c>"Possible"</c>
### Example 5
#### Input
<c>3,<br />5,<br />[<br /> 10,6,8,9,7,<br /> 5,1,3,4,2,<br /> 15,11,13,14,12<br />]</c>
#### Output
<c>"Possible"</c>
### Example 6
#### Input
<c>6,<br />2,<br />[<br /> 11,12,<br /> 2,1,<br /> 9,10,<br /> 7,8,<br /> 6,5,<br /> 3,4<br />]</c>
#### Output
<c>"Impossible"</c>

