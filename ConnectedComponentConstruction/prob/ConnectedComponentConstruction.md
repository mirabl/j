# [ConnectedComponentConstruction](/tc?module=ProblemDetail&rd=16849&pm=14466)
*Single Round Match 704 Round 1 - Division II, Level Two*

## Statement
Any undirected graph can be decomposed into connected components.
Two vertices u and v belong to the same connected component if we can travel from u to v by following a sequence of zero or more consecutive edges.
The size of a connected component is the number of vertices it contains.

You are given a int[] *s*.
Construct a simple undirected graph with the following properties:
The number of vertices is n, where n is the number of elements in *s*.
The vertices are numbered 0 through n-1.
For each i, the size of the connected component that contains vertex i is exactly *s*[i].

If there is no such graph, return an empty String[].
Otherwise, return a String[] ret with n elements, each containing n characters.
For each i and j, ret[i][j] should be 'Y' if there is an edge between i and j in your graph.
Otherwise, ret[i][j] should be 'N'.
If there are multiple solutions, you may return any of them.

## Definitions
- *Class*: `ConnectedComponentConstruction`
- *Method*: `construct`
- *Parameters*: `int[]`
- *Returns*: `String[]`
- *Method signature*: `String[] construct(int[] s)`

## Constraints
- *s* will contain between 1 and 50 elements, inclusive.
- Each element in s will be between 1 and |*s*|, inclusive.

## Examples
### Example 1
#### Input
<c>[2,1,1,2,1]</c>
#### Output
<c>["NNNYN", "NNNNN", "NNNNN", "YNNNN", "NNNNN" ]</c>
#### Reason
The answer is a graph that contains only one edge.
This edge connects the vertices 0 and 3.
This graph has four connected components: {0, 3}, {1}, {2}, and {4}.

### Example 2
#### Input
<c>[1,1,1,1]</c>
#### Output
<c>["NNNN", "NNNN", "NNNN", "NNNN" ]</c>
#### Reason
Here the only correct answer is a graph with four vertices and no edges.

### Example 3
#### Input
<c>[3,3,3]</c>
#### Output
<c>["NYY", "YNY", "YYN" ]</c>
#### Reason
This time one correct answer could be the complete graph on three vertices.

### Example 4
#### Input
<c>[4,4,4,4,4]</c>
#### Output
<c>[ ]</c>
#### Reason
There is no solution.

### Example 5
#### Input
<c>[1]</c>
#### Output
<c>["N" ]</c>

