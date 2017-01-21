# [AlphabetOrderDiv2](/tc?module=ProblemDetail&rd=16856&pm=14474)
*Single Round Match 705 Sponsored by Blizzard Round 1 - Division II, Level Two*

## Statement
The ancient civilization of Nlogonia used the same 26 letters as modern English: 'a'-'z'.
However, we do not know the order in which these letters appeared in the Nlogonian alphabet.

One particular custom in Nlogonia was that in a good word the letters appear in non-decreasing order.
For example, in English the word "ciel" is not a good word because in the alphabet 'i' is after 'e'.
The word "ceil" is a good word because 'c' <= 'e' <= 'i' <= 'l'.

You are given the String[] *words*.
Each element of *words* is a nonempty string of lowercase English letters.
Return "Possible" if it is possible that all elements of *words* were good words in Nlogonian, and "Impossible" otherwise.

In other words, return "Possible" if and only if there is at least one possible Nlogonian alphabet such that the letters of each word in *words* are in non-decreasing alphabetical order.

## Definitions
- *Class*: `AlphabetOrderDiv2`
- *Method*: `isOrdered`
- *Parameters*: `String[]`
- *Returns*: `String`
- *Method signature*: `String isOrdered(String[] words)`

## Constraints
- *words* has between 2 and 100 elements inclusive.
- The size of each element of *words* will be between 1 and 100 inclusive.
- Elements of *words* contains only English lowercase letters from 'a' to 'z'.

## Examples
### Example 1
#### Input
<c>["single","round","match"]</c>
#### Output
<c>"Possible"</c>
#### Reason
One possible Nlogonian alphabet is "bfjkmapqrositchundglevwxyz".

### Example 2
#### Input
<c>["topcoder","topcoder"]</c>
#### Output
<c>"Impossible"</c>
#### Reason
The word "topcoder" can never be a good word.
The character 'o' cannot be both before 'p' and after 'p' in the alphabet.

### Example 3
#### Input
<c>["algorithm", "contest"]</c>
#### Output
<c>"Impossible"</c>
### Example 4
#### Input
<c>["pink","floyd"]</c>
#### Output
<c>"Possible"</c>
### Example 5
#### Input
<c>["gimnasia","y","esgrima","la","plata"]</c>
#### Output
<c>"Impossible"</c>
### Example 6
#### Input
<c>["hello","hello"]</c>
#### Output
<c>"Possible"</c>
#### Reason
This is a good word for any alphabet in which the letters 'h', 'e', 'l', and 'o' appear in this order.

### Example 7
#### Input
<c>["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]</c>
#### Output
<c>"Possible"</c>
#### Reason
In this case the English alphabet is one of the valid permutations.

### Example 8
#### Input
<c>["abc","bca"]</c>
#### Output
<c>"Impossible"</c>
#### Reason
'a' must come before 'c' (because of the first name) and after 'c' (because of the second name) and that is a contradiction. Thus, there is no valid solution.

### Example 9
#### Input
<c>["aaaaa","eeeee","iiiii","ooooo","uuuuu"]</c>
#### Output
<c>"Possible"</c>
#### Reason
Any order is valid in this case

### Example 10
#### Input
<c>["ab","bc","ca"]</c>
#### Output
<c>"Impossible"</c>

