# [DoubleWeights](/tc?module=ProblemDetail&rd=16689&pm=14191)
*Single Round Match 685 Round 1 - Division II, Level Two*

## Statement
We have a simple undirected graph G with n nodes, labeled 0 through n-1.
Each edge of this graph has two weights.
You are given the description of G encoded into String[]s *weight1* and *weight2*.
If nodes i and j are connected by an edge, both *weight1*[i][j] and *weight2*[i][j] are nonzero digits ('1'-'9'), and these represent the two weights of this edge.
Otherwise, both *weight1*[i][j] and *weight2*[i][j] are periods ('.').

Your task is to find the cheapest path from node 0 to node 1.
The cost of a path is calculated as (W1 * W2), where W1 is the sum of all first weights and W2 is the sum of all second weights of the edges on your path.
Return the smallest possible cost of a path from node 0 to node 1.
If there is no such path, return -1 instead.

## Definitions
- *Class*: `DoubleWeights`
- *Method*: `minimalCost`
- *Parameters*: `String[], String[]`
- *Returns*: `int`
- *Method signature*: `int minimalCost(String[] weight1, String[] weight2)`

## Constraints
- n will be between 2 and 20, inclusive.
- *weight1* and *weight2* will contain exactly n elements, each.
- Each element in *weight1* and *weight2* will contain exactly n characters.
- Each character in *weight1* and *weight2* will be '.' or '1' - '9'.
- For each i, *weight1*[i][i] = *weight2*[i][i] = '.'.
- For each i and j, *weight1*[i][j] = *weight1*[j][i].
- For each i and j, *weight2*[i][j] = *weight2*[j][i].
- *weight1*[i][j] = '.' if and only if *weight2*[i][j] = '.'.

## Examples
### Example 1
#### Input
<c>["..14",<br /> "..94",<br /> "19..",<br /> "44.."],<br />["..94",<br /> "..14",<br /> "91..",<br /> "44.."]</c>
#### Output
<c>64</c>
#### Reason
The best path is 0 -> 3 -> 1.
The cost of this path is (4+4) * (4+4) = 64.

Note that the other possible path (0 -> 2 -> 1) is more expensive.
Its cost is (1+9) * (9+1) = 100.

### Example 2
#### Input
<c>["..14",<br /> "..14",<br /> "11..",<br /> "44.."],<br />["..94",<br /> "..94",<br /> "99..",<br /> "44.."]</c>
#### Output
<c>36</c>
#### Reason
This time the best path is 0->2->1, the cost is (1+1) * (9+9) = 36.

### Example 3
#### Input
<c>["..",<br /> ".."],<br />["..",<br /> ".."]</c>
#### Output
<c>-1</c>
#### Reason
There is no path between node 0 and node 1, so you should return -1.

### Example 4
#### Input
<c>[".....9",<br /> "..9...",<br /> ".9.9..",<br /> "..9.9.",<br /> "...9.9",<br /> "9...9."],<br />[".....9",<br /> "..9...",<br /> ".9.9..",<br /> "..9.9.",<br /> "...9.9",<br /> "9...9."]</c>
#### Output
<c>2025</c>
### Example 5
#### Input
<c>[".4...1",<br /> "4.1...",<br /> ".1.1..",<br /> "..1.1.",<br /> "...1.1",<br /> "1...1."],<br />[".4...1",<br /> "4.1...",<br /> ".1.1..",<br /> "..1.1.",<br /> "...1.1",<br /> "1...1."]</c>
#### Output
<c>16</c>

