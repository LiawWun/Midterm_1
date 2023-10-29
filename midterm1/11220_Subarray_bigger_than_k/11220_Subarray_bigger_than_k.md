## Task Description

We define a subarray as a contiguous portion of an array, which means it is an array that is contained within another array.

For example, consider the array [1, 2, 3, 4], There are 10 non-empty subarrays. 

The subarrays are [1], [2], [3], [4], [1, 2], [2, 3], [3, 4], [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4].

Write a program to display all the subarrays where the product of all the elements in the subarray is greater than the integer k. If there is no subarray that meets the criteria, print "No solution".

When outputting the subarrays that meet the criteria, please obey to the following rules:

1. Each line represents a subarray, and elements between subarrays should be separated by spaces.

2. Subarrays with shorter lengths should be printed first.

3. When the lengths are the same, prioritize printing the subarray with the smaller index of the first element in the original array.

## Input Format
There will be two lines of input.

There are two numbers separated by a space in the first line. The first element indicates the size of the array, while the second element represents the target value, k.

The second line represents the elements in the array, **starting from index 0**, with each element separated by a space.

All inputs are of integer type.

## Output Format
If a solution exists, display the subarrays according to the rules mentioned above. If no solution exists, print "No solution".

## Sample Input 1
```
4 -1000
1 2 3 4
```

## Sample Output 1
```
1
2
3
4
1 2
2 3
3 4
1 2 3
2 3 4
1 2 3 4
```

## Sample Input 2
```
3 10
-3 1 -2
```

## Sample Output 2
```
No solution
```

## Sample Input 3
```
5 10
7 -1 3 -2 5
```

## Sample Output 3
```
7 -1 3 -2
-1 3 -2 5
7 -1 3 -2 5
```
