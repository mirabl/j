# [TriangleEasy](/tc?module=ProblemDetail&rd=16748&pm=14324)
*Single Round Match 693 Round 1 - Division II, Level One*

## Statement
You are given an undirected graph with *n* vertices numbered 0 through *n*-1.
For each valid i, there is an undirected edge connecting two different vertices *x*[i] and *y*[i].
No two edges connect the same pair of vertices.

A triangle is a set of three distinct vertices such that each pair of those vertices is connected by an edge.
Formally, three distinct vertices u,v,w are a triangle if the graph contains the edges (u,v), (v,w), and (w,u).

You are given the description of the graph: the int *n* and the int[]s *x* and *y*.
You are allowed to add edges to this graph.
You may add as many edges as you want, and each of them may connect any two vertices.
Your goal is to produce a graph that contains at least one triangle.
Compute and return the smallest number of edges you need to add.

## Definitions
- *Class*: `TriangleEasy`
- *Method*: `find`
- *Parameters*: `int, int[], int[]`
- *Returns*: `int`
- *Method signature*: `int find(int n, int[] x, int[] y)`

## Constraints
- *n* will be between 3 and 50, inclusive.
- *x* will have between 0 and *n**(*n*-1)/2 elements, inclusive.
- *y* will have the same number of elements as *x*.
- Each element of *x* and *y* will be between 0 and *n*-1, inclusive.
- For each valid i, *x*[i] != *y*[i].
- No two edges will connect the same pair of vertices.

## Examples
### Example 1
#### Input
<c>3,<br />[],<br />[]</c>
#### Output
<c>3</c>
#### Reason
The graph has three vertices but no edges. You need to add edges (0,1), (1,2), and (2,0) to make it a triangle.

### Example 2
#### Input
<c>4,<br />[0,2,1,2],<br />[3,0,2,3]</c>
#### Output
<c>0</c>
#### Reason
Note that the edges are undirected. The graph already has a triangle: (2,0),(0,3),(2,3), so we don't have to add anything.

### Example 3
#### Input
<c>6,<br />[0,0,2],<br />[3,1,4]</c>
#### Output
<c>1</c>
### Example 4
#### Input
<c>4,<br />[0,2],<br />[1,3]</c>
#### Output
<c>2</c>
### Example 5
#### Input
<c>20,<br />[16,4,15,6,1,0,10,12,7,15,2,4,8,1,10,15,13,10,1,16,3,19,8,7,13,1,15,15,15,5,16,7,5,6,4,18,3,8,6,2,16,8,19,14,17,16,4,6,9,17,4,10,8,12,2,3,18,9,13,17,4,7,10,0,13,11,15,17,11,15,11,19,19,4,10,14,16,6,3,17,1,4,14,9,7,18,10,11,5,0,5,9,9,7,16,12,4,10,17,3],<br />[17,18,6,16,18,6,11,2,15,10,1,15,17,8,5,9,7,0,0,4,16,1,9,0,9,5,17,14,1,12,14,11,9,18,0,12,11,3,19,14,7,6,3,19,0,1,19,5,11,19,2,13,12,0,6,2,14,16,14,18,5,5,19,3,6,14,12,5,17,3,1,12,7,11,8,8,10,11,13,2,13,13,0,18,2,7,2,12,14,9,3,19,2,8,12,13,8,18,13,18]</c>
#### Output
<c>1</c>

