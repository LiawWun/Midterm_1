## Task Description

Given a two-dimensional character array, where each row represents a string and each string has a size not exceeding 15 characters, the task is to identify the biggest and smallest strings, as well as the rows that contain these strings. The biggest and smallest of the strings are determined by the **strcmp** function in the **string.h** library.

The `main.c` function is as follows:
```c
#include <stdio.h>
#include <string.h>
#include "getMaxMin.h"
int main(){
  int string_num = 0;
  scanf ("%d", &string_num);
  char string_arr[string_num][16];
  for (int i = 0; scanf("%s", &(string_arr[i][0])) != EOF; i++ ){}
  char *min_str, *max_str;
  int min_idx, max_idx;
  getMaxMin(string_arr, string_num, &min_idx, &min_str, &max_idx, &max_str);
  printf("Max string: %s\n", max_str);
  printf("Max string index: %d\n", max_idx);
  printf("Min string: %s\n", min_str);
  printf("Min string index: %d\n", min_idx);
  return 0;
}
```

You need to implement the function in `getMaxMin.c` and pass the answers back to **main.c** using pointers, and **main.c** will print out the results. 

```c
void getMaxMin(char string_arr[][16], int size, int *min_idx, char **min, int *max_idx, char **max)
{	
  // TBD
}
```

**char_arr[][16]** represents the input two-dimensional character array, where each row is a string.

**size** indicates the total number of strings.

***min_idx**  represents the row where the smallest string is located.

****min** represents the smallest string in the array.

***max_idx** represents the row where the biggest string is located.

****max** represents the smallest string in the array.


## Input Format
The first line is a positive integer, indicating the total number of strings to be compared.

Each subsequent line represents a string.


## Output Format

The output consists of four lines. The first line represents the maximum string, the second line represents the row where the maximum string is located, the third line represents the minimum string, and the fourth line represents the row where the minimum string is located.


## Sample Input 1
```
5
apple
banana
orange
grape
kiwi
```

## Sample Output 1
```
Max string: orange
Max string index: 2
Min string: apple
Min string index: 0

```

## Sample Input 2
```
3
Jim
Bob
Roy
Ray
```

## Sample Output 2
```
Max string: Roy
Max string index: 2
Min string: Bob
Min string index: 1
```