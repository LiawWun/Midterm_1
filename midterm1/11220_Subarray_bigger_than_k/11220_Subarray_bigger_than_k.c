#include<stdio.h>
int main(){
  int arr_size, target, value = 1, solution_found = 0;
  scanf("%d %d", &arr_size, &target);
  int numbers[arr_size];
  for (int i = 0; scanf("%d", &(numbers[i])) != EOF; i++){}
  for (int window_size = 1; window_size <= arr_size; window_size++){
    for (int left_side = 0; left_side <= arr_size - window_size; left_side ++ ){
      int right_side = left_side + window_size - 1;
      for (int idx = left_side; idx <= right_side; idx ++){
	value *= numbers[idx];
      }
      if (value > target ){
	solution_found = 1;
	for (int idx = left_side; idx <= right_side; idx ++) {
	  printf( idx == right_side ? "%d" : "%d ", numbers[idx]);
	}
	printf("\n");
      }
      value = 1;
      }
  }
  if( solution_found == 0 ) printf("No solution");
  return 0;
}
