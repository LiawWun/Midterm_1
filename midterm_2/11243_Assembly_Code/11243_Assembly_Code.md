## Task Description

In this task, you will be provided with an assembly language code. Your objective is to write a C program that simulates this code and displays the values stored in registers (x0 to x7). Assuming that initially, the values in the registers are all set to 0.

You are required to implement the following assembly language instructions.

|   Instruction	|  Explanation 	|
|:-:	|:-:	|
| **add,x_d,x_src1,x_src2**  	|   The value in x_d is equal to the sum of the values in x_src1 and x_src2.	|
| **sub,x_d,x_src1,x_src2**  	|   The value in x_d is equal to the value in x_src1 minus the value in x_src2.	   	|
| **addi,x_d,x_src1,constant**  |   The value in x_d is equal to the value in x_src1 plus a constant.	   	|
| **beq,x_src1,x_src2,offset**  |   If the value in x_src1 is equal to the value in x_src2, then <br> program_counter = program_counter + offset.	|
| **bge,x_src1,x_src2,offset**  |   If the value in x_src1 is greater than or equal to the value in x_src2, then <br> program_counter = program_counter + offset    |
| **end**  |  end of program     |


Below are some characteristics of the test data that can help simplify the program design.

1. All register identifiers are single-digit numbers, ranging from 0 to 7.

2. The range of the constant is from -9 to 9.

3. The range of the offset is from -9 to 9.


## Input Format
Assembly language, where each line represents a single instruction.


## Output Format
One line consists of eight integers, each separated by a space, representing the numbers stored in registers x0 to x7.

## Sample Input 1
```
addi,x0,x0,-3
addi,x1,x1,9
addi,x2,x2,0
bge,x1,x0,3
sub,x2,x0,x1
beq,x0,x0,2
sub,x2,x1,x0
end
```

## Sample Output 1
```
-3 9 12 0 0 0 0 0
```


## Sample Input 2
```
addi,x0,x0,-1
addi,x1,x1,-2
addi,x2,x2,-3
addi,x3,x3,-4
add,x5,x0,x1
add,x6,x2,x3
add,x7,x5,x6
```


## Sample Output 2
```
-1 -2 -3 -4 0 -3 -7 -10
```
