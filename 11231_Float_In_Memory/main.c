#include<stdio.h>
#include"ConvertToFloat.h"
#define REG_SIZE 32
int main(){
	int *reg_ptr, reg[REG_SIZE];
	reg_ptr = reg;
	for (int i = 0; i < REG_SIZE; i++) scanf("%d", &(reg[i]));
  printf("%.6f\n", ConvertToFloat(reg_ptr));
	return 0;
}
