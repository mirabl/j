# [Quacking](/tc?module=ProblemDetail&rd=16708&pm=14218)
*Single Round Match 687 Round 1 - Division II, Level Two*

## Statement
Ducks have started mysteriously appearing in your room.
All ducks make the same sound: "quack".
Each duck makes the sound one or more times, one after another.
For example, valid sounds for a single duck are "quack", "quackquackquackquack", "quackquack", etc.

You have lost count of how many ducks are in your room.
The ducks are quacking, and the sounds of their quacks are getting mixed up.
You have recorded the sounds, obtaining a String of characters.
When you later listened to the recording, you realized that the quacking of each individual duck forms a (not necessarily contiguous) subsequence of the recording.
You also noticed that each letter in the recording belongs to exactly one duck.
For example, if there were two ducks, you may have recorded "quqacukqauackck".

You are given a String *s* that contains an arbitrary recording.
Find and return the smallest number of ducks that could have produced the recording.
Note that it is possible that the given recording is not a valid recording of quacking ducks.
In such case, return -1.

## Definitions
- *Class*: `Quacking`
- *Method*: `quack`
- *Parameters*: `String`
- *Returns*: `int`
- *Method signature*: `int quack(String s)`

## Constraints
- *s* will have between 5 and 2,500 characters, inclusive.
- Each character of *s* will be 'q', 'u', 'a', 'c', or 'k'.

## Examples
### Example 1
#### Input
<c>"quqacukqauackck"</c>
#### Output
<c>2</c>
#### Reason
This is the same as the one from the problem statement.

### Example 2
#### Input
<c>"kcauq"</c>
#### Output
<c>-1</c>
#### Reason
A backward duck is not a real duck.

### Example 3
#### Input
<c>"quackquackquackquackquackquackquackquackquackquack"</c>
#### Output
<c>1</c>
#### Reason
A single duck can make arbitrarily many quack sounds.

### Example 4
#### Input
<c>"qqqqqqqqqquuuuuuuuuuaaaaaaaaaacccccccccckkkkkkkkkk"</c>
#### Output
<c>10</c>
### Example 5
#### Input
<c>"quqaquuacakcqckkuaquckqauckack"</c>
#### Output
<c>3</c>
#### Reason
This is one possible solution with 3 ducks.
Mixed: quqaquuacakcqckkuaquckqauckack
Duck1: ____q_u__a___ck_______________
Duck2: __q__u_ac_k_q___ua__ckq_u__ack
Duck3: qu_a_______c___k__qu___a_ck___
Here, we can verify that each letter comes from exactly one duck.

### Example 6
#### Input
<c>"quackqauckquack"</c>
#### Output
<c>-1</c>
#### Reason
Note that the second quack is misspelled.


