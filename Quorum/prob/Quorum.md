# [Quorum](/tc?module=ProblemDetail&rd=16708&pm=14219)
*Single Round Match 687 Round 1 - Division II, Level Two*

## Statement
In one organization they have n different committees.
The organization has a very large number of employees.
Each employee is a member of each committee.

Each committee has a quorum: the smallest number of members that have to be present to have an official meeting.
You are given a int[] *arr* with n elements.
Each element of *arr* is the quorum of one committee.

You are also given an int *k*.
Yesterday, *k* different committees had an official meeting, all at the same time.
Obviously, each person attended at most one of those meetings.
Compute and return the smallest possible number of people who attended a meeting yesterday.

## Definitions
- *Class*: `Quorum`
- *Method*: `count`
- *Parameters*: `int[], int`
- *Returns*: `int`
- *Method signature*: `int count(int[] arr, int k)`

## Notes
- The value of n is not given explicitly. Instead, you can determine it as the number of elements in *arr*.

## Constraints
- *arr* will contain between 1 and 50 elements, inclusive.
- Each element of *arr* will be between 1 and 50.
- *k* will be between 1 and the number of elements of *arr*, inclusive.

## Examples
### Example 1
#### Input
<c>[5,2,3],<br />1</c>
#### Output
<c>2</c>
#### Reason
There are three committees.
The first committee requires 5 members to start a meeting, the second requires 2, and the third requires 3 members.
As *k*=1, there was one meeting yesterday.
The smallest possible solution is that it was a meeting of the second committee and that exactly 2 employees attended that meeting.

### Example 2
#### Input
<c>[1,1,1,1,1],<br />5</c>
#### Output
<c>5</c>
#### Reason
All five committees had a meeting yesterday.
We need at least one person per meeting.
No person can attend more than one meeting.
Hence, there must have been at least 5 different people.

### Example 3
#### Input
<c>[50,2,9,49,38],<br />3</c>
#### Output
<c>49</c>
### Example 4
#### Input
<c>[20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1],<br />14</c>
#### Output
<c>105</c>

