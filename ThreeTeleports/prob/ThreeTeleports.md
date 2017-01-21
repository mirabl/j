# [ThreeTeleports](/tc?module=ProblemDetail&rd=14544&pm=11554)
*Single Round Match 519 Round 1 - Division II, Level Two*

## Statement
You are a frog. You live on an infinite lattice of grid points. For each pair of integers x, y there is a grid point with coordinates (x,y). At this moment, you sit on the grid point (*xMe*,*yMe*). You want to get home: to the grid point (*xHome*,*yHome*).

There are two ways in which you can travel. Your first option is jumping: if you are at (x,y), you can jump to one of the four neighboring grid points: (x+1,y), (x-1,y), (x,y+1), or (x,y-1). Each jump takes one second.

Your second option is using a teleport. There are three teleports in the entire world. Each of them connects two different grid points. If you are at one of the endpoints, you may activate the teleport and travel to its other endpoint. Traveling by teleport takes 10 seconds.

You are given ints *xMe*, *yMe*, *xHome*, *yHome*, and a String[] *teleports* that describes the three teleports. Each element of *teleports* will be a String containing four integers x1, y1, x2, and y2, separated by single spaces. These integers describe a teleport with endpoints at (x1,y1) and (x2,y2).

Your method must return the shortest time in which you can reach your home.

## Definitions
- *Class*: `ThreeTeleports`
- *Method*: `shortestDistance`
- *Parameters*: `int, int, int, int, String[]`
- *Returns*: `int`
- *Method signature*: `int shortestDistance(int xMe, int yMe, int xHome, int yHome, String[] teleports)`

## Notes
- Traveling by a teleport is not mandatory. You may pass through its endpoint and decide not to use it.

## Constraints
- *xMe*, *yMe*, *xHome*, and *yHome* will all be between 0 and 1,000,000,000, inclusive.
- *teleports* will have exactly three elements.
- Each element of *teleports* will have the following format: "x1 y1 x2 y2" (quotes for clarity), where x1, y1, x2, and y2 are integers between 0 and 1,000,000,000, inclusive. The integers x1, y1, x2, and y2 will not contain unnecessary leading zeroes.
- All eight points (your location, the location of your home, and the six teleport endpoints) will be pairwise distinct.

## Examples
### Example 1
#### Input
<c>3,<br />3,<br />4,<br />5,<br />["1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"]</c>
#### Output
<c>3</c>
#### Reason
The frog must make at least 3 leaps. For example, from (3,3) to (3,4), then to (3,5), and finally to (4,5). The teleports are all too far away to be useful.

### Example 2
#### Input
<c>0,<br />0,<br />20,<br />20,<br />["1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"]</c>
#### Output
<c>14</c>
#### Reason
The journey can be done in 40 jumps = 40 seconds, but there is a better solution: Make 2 jumps to get from (0,0) to (1,1), use the teleport to get to (18,20), and make 2 jumps to get to (20,20). This solution takes (2+10+2) = 14 seconds.

### Example 3
#### Input
<c>0,<br />0,<br />20,<br />20,<br />["1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"]</c>
#### Output
<c>14</c>
#### Reason
The teleports may be used in either direction, and in any order.

### Example 4
#### Input
<c>10,<br />10,<br />10000,<br />20000,<br />["1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"]</c>
#### Output
<c>30</c>
### Example 5
#### Input
<c>3,<br />7,<br />10000,<br />30000,<br />["3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"]</c>
#### Output
<c>117</c>
#### Reason
Sometimes the best solution requires us to use more than one teleport. In this case, the optimal solution looks as follows:

Using jumps, travel to (3,10).
Use the first teleport.
Using jumps, travel from (5200,4900) to (5203,4845).
Use the third teleport.
Using jumps, travel from (12200,8701) to (12212,8699).
Use the second teleport.
Using jumps, travel from (9999,30011) to (10000,30000).

### Example 6
#### Input
<c>0,<br />0,<br />1000000000,<br />1000000000,<br />["0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"]</c>
#### Output
<c>36</c>
#### Reason
Watch out for overflows. The correct return value will always fit into a int, but some other paths may be very long.


