# [NonDeterministicSubstring](/tc?module=ProblemDetail&rd=16710&pm=14246)
*Single Round Match 689 Round 1 - Division II, Level Two*

## Statement
You are given two Strings: *A* and *B*.
Each character in *A* is either '0' or '1'.
Each character in *B* is '0', '1', or '?'.

A string C matches *B* if we can change *B* into C by changing each '?' in *B* either to '0' or to '1'.
Different occurrences of '?' may be changed to different digits.
For example, C = "0101" matches *B* = "01??".
Note that each character in C must be either '0' or '1', there cannot be any '?' remaining.

Consider all possible strings that match *B*.
How many of these strings occur as a (contiguous) substring in *A*?
Compute and return their number.
Note that we only count each good string once, even if it has multiple occurrences in *A*.

## Definitions
- *Class*: `NonDeterministicSubstring`
- *Method*: `ways`
- *Parameters*: `String, String`
- *Returns*: `long`
- *Method signature*: `long ways(String A, String B)`

## Constraints
- *A* will contain between 1 and 50 characters, inclusive.
- *B* will contain between 1 and 50 characters, inclusive.
- Each character in *A* will be '0' or '1'.
- Each character in *B* will be '0', '1' or '?'.

## Examples
### Example 1
#### Input
<c>"00010001",<br />"??"</c>
#### Output
<c>3</c>
#### Reason
There are four strings that match *B*: the strings "00", "01", "10", and "11".
Out of these, the string "11" does not occur in *A* as a substring.
The other three do occur, hence the answer is 3.

### Example 2
#### Input
<c>"00000000",<br />"??0??0"</c>
#### Output
<c>1</c>
#### Reason
There are 16 different strings that match *B*, but out of those only the string "000000" is a substring of *A*.

### Example 3
#### Input
<c>"001010101100010111010",<br />"???"</c>
#### Output
<c>8</c>
#### Reason
Each of the 8 strings that match *B* occurs somewhere in *A*.

### Example 4
#### Input
<c>"00101",<br />"??????"</c>
#### Output
<c>0</c>
#### Reason
Here, the length of *B* is greater than the length of *A*.
Clearly, a string that matches this *B* cannot be a substring of this *A*.

### Example 5
#### Input
<c>"1101010101111010101011111111110001010101",<br />"???????????????????????????????????"</c>
#### Output
<c>6</c>

