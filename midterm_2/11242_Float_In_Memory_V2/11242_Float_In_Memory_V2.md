## Task Description

In the 11/09 quiz, you learned how to determine the decimal representation of a floating-point number using 32 bits. In this task, please reverse the process and convert a decimal floating-point number back to 32 bits of 0s and 1s.

When a floating-point number is stored in 32 bits of memory, it is divided into three sections: the Sign bit, the Exponent, and the Mantissa.

![image](https://lh3.googleusercontent.com/pw/ADCreHcs4UkE2BCeEGyKDMGRHl8Je_jGlEUJRx2Dj0_OolV5mRkHnO4QCYppEKgWWHO0sNqtwtEsEGt7StGuumpvjYV3x56HidqvDdUq2-J0A-o2gBWP2X4=w1800)

The first bit (at index 0) is called the sign bit, which represents the sign of this float. A value of 0 indicates that the float is positive, while a value of 1 indicates that the float is negative.

The next 8 bits (index 1 to index 8) are called the Exponent, representing the exponent part of this float.

The remaining bits (index 9 to index 31) are called the Mantissa, representing the decimal fraction part of this float.

You can follow the steps below to convert a floating-point number into its 32-bit binary representation.

1. Determine the sign bit by inspect the sign of the floating-point number, and convert to the positive value.

2. If the absolute value of the input floating-point number is greater than 1, divide it by 2 repeatedly until the integer part becomes 1. At this point, calculate the exponent as **127 plus the number of times it was divided by 2**. If the absolute value of the input fraction is less than 1, multiply it by 2 repeatedly until the integer part becomes 1. At this point, calculate the exponent as **127 minus the number of times it was divided by 2**.

3. Mantissa is the fractional part of the converted floating-point number.

Below are two examples.

![image](https://lh3.googleusercontent.com/pw/ADCreHdRSZLxxyeIkfZrSEoXu5O28CsMPigeBT09ptpHyeEk8JAvmMnEANvgo5phD0VrxjxWppT639QUYe3ZZTzuZZGHb4FqreHKgc4BkM297568NNxsKGs=w800)

## Input Format
A floating-point number.


## Output Format
A sequence composed of 32 elements representing the values of each bit in memory. Each element is separated by spaces and consists of either 0 or 1.


## Sample Input 1
```
12.5
```

## Sample Output 1
```
0 1 0 0 0 0 0 1 0 1 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```

## Sample Input 2
```
-0.875
```

## Sample Output 2
```
1 0 1 1 1 1 1 1 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```