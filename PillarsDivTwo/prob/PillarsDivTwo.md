# [PillarsDivTwo](/tc?module=ProblemDetail&rd=14739&pm=12075)
*Single Round Match 547 Round 1 - Division II, Level Two*

## Statement
On a horizontal line, there are N uniformly spaced vertical pillars.
The pillars are numbered 0 through N-1, in order.
For each i, the distance between the bottoms of pillars i and i+1 is exactly *w*.
For each i, the height of pillar i (0-based index) is an integer between 1 and *heights*[i], inclusive.
We want to take a single piece of rope and use it to join the top ends of all pillars, in order.
(Once in place, the rope will have the shape of a polyline consisting of N-1 segments.)
What is the shortest length of rope that is guaranteed to be sufficient, regardless of the actual pillar heights?

You are given the int[] *heights* and the int *w*.
Compute and return the answer to the above question.
In other words, find a sequence of pillar heights (within the given constraints) for which the length of the rope we need is maximized, and return that maximum.

## Definitions
- *Class*: `PillarsDivTwo`
- *Method*: `maximalLength`
- *Parameters*: `int[], int`
- *Returns*: `double`
- *Method signature*: `double maximalLength(int[] height, int w)`

## Notes
- Your return value must have a relative or an absolute error of less than 1e-9.

## Constraints
- *heights* will contain between 1 and 50 elements, inclusive.
- Each element of *heights* will be between 1 and 100, inclusive.
- *w* will be between 1 and 100, inclusive.

## Examples
### Example 1
#### Input
<c>[3,3,3],<br />2</c>
#### Output
<c>5.656854249492381</c>
### Example 2
#### Input
<c>[1,1,1,1],<br />100</c>
#### Output
<c>300.0</c>
### Example 3
#### Input
<c>[100,2,100,2,100],<br />4</c>
#### Output
<c>396.32310051270036</c>
#### Reason
We will need the most rope if columns 0, 2, and 4 have height 100 each, and columns 1 and 3 have height 1 each.

### Example 4
#### Input
<c>[2,1,1,2],<br />1</c>
#### Output
<c>3.82842712474619</c>

