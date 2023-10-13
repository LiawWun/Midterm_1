## Task Description
Write a program to calculate the number of days between two dates, excluding the last day **(no need to add 1)**. You cannot use the <time.h> library.

The following information might be helpful to you.
1. If the year is divisible by 4 but not by 100, it is a leap year.

2. If the year is divisible by 400, it is also a leap year.

3. Try using an additive approach to analyze this problem. Let's consider an example: If we start on 3/5 and go through 27 days, we will reach 4/1. (It's like a carry-over of days). Moving forward, 19 more days will bring us to 4/20. Therefore, we can conclude that the difference between 4/20 and 3/5 is 27 + 19 = 46 days.

4. We can first initialize an array to store the number of days for each of the 12 months. This array will indicate when we should carry over the days.
```C 
 int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```


## Input Format
Two input lines, each representing YYYY MM DD.

The first line is the starting date, and the second line is the ending date.

All input data is valid.

## Output Format
The output is an integer representing the number of days between the two dates.

## Sample Input 1
```
1900 02 28
1900 03 01
```

## Sample Output 1
```
1
```
Since 1900 is not a leap year, the difference is 1 day. (02/28)
## Sample Input 2
```
2000 02 28
2000 03 01
```

## Sample Output 2
```
2
```
Since 2000 is a leap year, the difference is 2 days. (02/28, 02/29)
## Sample Input 3
```
1999 01 01
2001 03 04
```

## Sample Output 2
```
793
```
From 1999 01 01 --> 2000 01 01 ==> 365 days. (1999 is not a leap year)

From 2000 01 01 --> 2001 01 01 ==> 366 days. (2000 is a leap year)

From 2001 01 01 --> 2001 02 01 ==> 31 days.

From 2001 02 01 --> 2001 03 01 ==> 28 days.

From 2001 03 01 --> 2001 03 04 ==> 3 days.

Total = 365 + 366 + 31 + 28 + 3 = 793 days.