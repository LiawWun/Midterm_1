## Task Description
The Collatz conjecture(猜想), also known as the 3n+1 conjecture, is an intriguing and unsolved mathematical problem. According to this conjecture, regardless of the initial positive integer "n," as long as we continuously apply the following rules to it, we will eventually reach the number 1.

1. If the current number is even, divide it by 2.
2. If the current number is odd, multiply it by 3, and then add 1.
   
Your task is to create a program to verify the Collatz conjecture. Your program should accept a positive integer as input and then process it according to the rules of the Collatz conjecture until it reaches 1. Your program should output the total number of steps required for "n" to reach 1 and the maximum value reached during the process.

Requirement:

You need to create a function that takes a positive integer as input and process it according to the rules of the Collatz conjecture, ultimately returning the processed value. 
```C
int CollatzConjecture(int num)
```

## Input Format
One positive integer **n**.

## Output Format
Two positive integers separated by a space.

The first integer represents the number of steps required from n to 1.

The second integer represents the maximum value reached during the process.

## Sample Input 1
```
6
```

## Sample Output 1
```
8 16
```
Explanation:

**step 1**: 6 -> 3 (6 is even)

**step 2**: 3 -> 10 (3 is odd)

**step 3**: 10 -> 5 (10 is even)

**step 4**: 5 -> 16 (5 is odd)

**step 5**: 16 -> 8 (16 is even, and 16 is the maximum value during the process)

**step 6**: 8 -> 4 (8 is even)

**step 7**: 4 -> 2 (4 is even)

**step 8**: 2 -> 1 (2 is even)

## Sample Input 2
```
27
```

## Sample Output 2
```
111 9232
```
