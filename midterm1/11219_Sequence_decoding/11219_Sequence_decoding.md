## Task Description

The sequence is composed of combinations of numbers from 1 to m, forming a sequence of length m. The elements in the sequence are all unique. In other words, all numbers from 1 to m appear **exactly once** in the sequence.

We will encrypt this sequence into a new sequence { $b_1$, $b_2$, $b_3$, $b_4$,..., $b_m$}. In the encrypted sequence, ' $b_m$ ' represents the count of numbers greater than 'm' in the original sequence that appear before 'm'.

You will be given an encrypted sequence of length m. Please write a program to decrypt this sequence.

The encrypted sequence might be impossible to decrypt. Your program should also be able to identify sequences that cannot be decrypted.

 If we apply the encryption to {2, 1, 5, 4, 3}, we will obtain the encrypted sequence {1, 0, 2, 1, 0}.

 Below is the explanation for the encrypted sequence {1, 0, 2, 1, 0}.

 $m = 1 ,b_1 = 1$, In the original sequence, there are 1 numbers before '1' that are greater than '1'.

 $m = 2 ,b_2 = 0$, In the original sequence, there are 0 numbers before '2' that are greater than '2'.

 $m = 3 ,b_3 = 2$, In the original sequence, there are 2 numbers before '3' that are greater than '3'.

 $m = 4 ,b_4 = 1$, In the original sequence, there are 1 numbers before '4' that are greater than '4'.

 $m = 5 ,b_5 = 0$, In the original sequence, there are 0 numbers before '5' that are greater than '5'.

For those who have no idea why there are some sequences that can't be decrypted, try to consider the following question.

1. Why is the last element of the encrypted sequence is 0?

2. Why is the maximum value for the first element in the encrypted sequence is (m - 1)?

3. What is the maximum possible value for each element '$b_m$' in the encrypted sequence?

## Input Format
There will be two lines of input.

The first line represents the length of the encrypted sequence.

The second line represents each number in the encrypted sequence, separated by spaces.

## Output Format
If the sequence can be decrypted, output the decrypted sequence. Separate each element in the sequence by spaces.
If the sequence cannot be decrypted, please output 'No answer'.

## Sample Input 1
```
10
3 5 5 5 1 0 1 1 0 0
```

## Sample Output 1
```
6 5 9 1 7 8 2 3 4 10
```

## Sample Input 2
```
7
1 1 1 1 1 1 0
```

## Sample Output 2
```
7 1 2 3 4 5 6
```

## Sample Input 3
```
5
2 4 3 1 1
```

## Sample Output 3
```
No answer
```
