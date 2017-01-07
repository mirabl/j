# [OrderOfOperationsDiv2](/tc?module=ProblemDetail&rd=16547&pm=13988)
*Single Round Match 667 Round 1 - Division II, Level Two*

## Statement
Cat Noku has just finished writing his first computer program.
Noku's computer has m memory cells.
The cells have addresses 0 through m-1.
Noku's program consists of n instructions.
The instructions have mutually independent effects and therefore they may be executed in any order.
The instructions must be executed sequentially (i.e., one after another) and each instruction must be executed exactly once.

You are given a description of the n instructions as a String[] with n elements.
Each instruction is a String of m characters.
For each i, character i of an instruction is '1' if this instruction accesses memory cell i, or '0' if it does not.

Noku's computer uses caching, which influences the time needed to execute an instruction.
More precisely, executing an instruction takes k^2 units of time, where k is the number of new memory cells this instruction accesses.
(I.e., k is the number of memory cells that are accessed by this instruction but have not been accessed by any previously executed instruction.
Note that k may be zero, in which case the current instruction is indeed executed in 0 units of time.)

Noku's instructions can be executed in many different orders.
Clearly, different orders may lead to a different total time of execution.
Find and return the shortest amount of time in which it is possible to execute all instructions.

## Definitions
- *Class*: `OrderOfOperationsDiv2`
- *Method*: `minTime`
- *Parameters*: `String[]`
- *Returns*: `int`
- *Method signature*: `int minTime(String[] s)`

## Constraints
- n,m will be between 1 and 20, inclusive.
- *s* will have exactly n elements.
- Each element of *s* will have exactly m characters.
- Each character of *s*[i] will be either '0' or '1' for all valid i.

## Examples
### Example 1
#### Input
<c>[<br /> "111",<br /> "001",<br /> "010"<br />]</c>
#### Output
<c>3</c>
#### Reason
Cat Noku has 3 instructions.
The first instruction ("111") accesses all three memory cells.
The second instruction ("001") accesses only memory cell 2.
The third instruction ("010") accesses only memory cell 1.
If Noku executes these three instructions in the given order, it will take 3^2 + 0^2 + 0^2 = 9 units of time.
However, if he executes them in the order "second, third, first", it will take only 1^2 + 1^2 + 1^2 = 3 units of time.
This is one optimal solution.
Another optimal solution is to execute the instructions in the order "third, second, first".

### Example 2
#### Input
<c>[<br /> "11101",<br /> "00111",<br /> "10101",<br /> "00000",<br /> "11000"<br />]</c>
#### Output
<c>9</c>
### Example 3
#### Input
<c>[<br />  "11111111111111111111"<br />]</c>
#### Output
<c>400</c>
#### Reason
A single instruction that accesses all 20 memory cells.

### Example 4
#### Input
<c>[<br />  "1000",<br />  "1100",<br />  "1110"<br />]</c>
#### Output
<c>3</c>
### Example 5
#### Input
<c>[<br />  "111",<br />  "111",<br />  "110",<br />  "100"<br />]</c>
#### Output
<c>3</c>

