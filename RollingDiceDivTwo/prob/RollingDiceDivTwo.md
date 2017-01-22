# [RollingDiceDivTwo](/tc?module=ProblemDetail&rd=14728&pm=11801)
*Single Round Match 536 Round 1 - Division II, Level Two*

## Statement
Byteasar is playing a tabletop role-playing game with his friends. To determine the effectiveness of their heroes' actions the players use a rather unique set of dice which may have nonequal number of faces. Each die has between 1 and 9 faces, inclusive. If a die has m faces, they contain precisely all the values between 1 and m, inclusive. More precisely, for each k between 1 and m, inclusive, there is one face that shows exactly k pips. When a die is cast, every face has equal probability to come out on top.

Every time all the dice were thrown at once, Byteasar wrote down the numbers of pips visible on each of the topmost faces (in any order). The results of the i-th throw are given in *throws*[i]; the length of *throws*[i] is equal to the number of dice and each character of *throws*[i] denotes the number of pips visible on one of the topmost faces. For example, if *throws*[3][0]='7', this means that in throw 3 (0-based index) one of the dice showed exactly 7 pips on the top. Please note that the ordering of dice may be different for different throws.

Given the String[] *throws* containing Byteasar's notes, return the minimum possible total number of faces of all dice.

## Definitions
- *Class*: `RollingDiceDivTwo`
- *Method*: `minimumFaces`
- *Parameters*: `String[]`
- *Returns*: `int`
- *Method signature*: `int minimumFaces(String[] rolls)`

## Notes
- Please note that a die can have as few as one or two faces.

## Constraints
- *rolls* will contain between 1 and 50 elements, inclusive.
- *rolls*[0] will contain between 1 and 50 characters, inclusive.
- All elements of *rolls* will contain the same number of characters.
- Each character in each element of *rolls* will be one of '1'-'9'.

## Examples
### Example 1
#### Input
<c>["137", "364", "115", "724"]</c>
#### Output
<c>14</c>
#### Reason
In the first throw the numbers of pips on the topmost faces of the dice were 1, 3 and 7; in the second throw they were 3, 6 and 4, in the third they were 1, 1 and 5 and in the fourth roll they were 7, 2 and 4. The players may have used dice with 3, 4 and 7 faces, giving a total of 14 faces. No other possible set of dice has less faces in total.

### Example 2
#### Input
<c>["1112", "1111", "1211", "1111"]</c>
#### Output
<c>5</c>
#### Reason
The players could have used three dice with one face each and one die with two faces.

### Example 3
#### Input
<c>["24412", "56316", "66666", "45625"]</c>
#### Output
<c>30</c>
#### Reason
The players could have used five dice with six faces each.

### Example 4
#### Input
<c>["931", "821", "156", "512", "129", "358", "555"]</c>
#### Output
<c>19</c>
### Example 5
#### Input
<c>["3", "7", "4", "2", "4"]</c>
#### Output
<c>7</c>
### Example 6
#### Input
<c>["281868247265686571829977999522", "611464285871136563343229916655", "716739845311113736768779647392", "779122814312329463718383927626",<br />"571573431548647653632439431183", "547362375338962625957869719518", "539263489892486347713288936885", "417131347396232733384379841536"]</c>
#### Output
<c>176</c>

