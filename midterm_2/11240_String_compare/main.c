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