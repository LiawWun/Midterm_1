#include<stdio.h>
int main(){
  int layer = 0, length = 0;
  scanf("%d", &layer);
  length = (2 * layer) - 1;
  for (int i = 1; i <= layer; i ++){
	  int stone_number = (2 * i) - 1;
    int space_number = (length - stone_number) / 2;
	  for (int j = 1; j <= space_number; j ++) printf("_");
	  for (int k = 1; k <= stone_number; k ++) printf("*"); 
	  for (int l = 1; l <= space_number; l ++) printf("_");
	  printf("\n");
  }
  return 0;
}