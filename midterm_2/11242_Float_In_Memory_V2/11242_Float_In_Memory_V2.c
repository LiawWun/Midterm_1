#include <stdio.h>
int main(){
  int ans[32] = {0}; // sign bit 0, exponent bits 1 ~ 8, mantissa bits 9 ~ 31
  float num;
  scanf ("%f", &num);
  // Determine sign bit
  ans[0] = num > 0 ? 0 : 1;
  num = num > 0 ? num : -num;
  // Calculate Exponent
  int exponent = 127;
  if (num < 1) for (exponent = 127; num < 1; num*= 2, exponent --){}
  else for (exponent = 127; num > 2; num/=2, exponent ++){}	
  for (int i = 1, term = 128; i <= 8; i++, term /=2){
	ans[i] = (int)(exponent / term);
	exponent = ans[i] == 1 ? exponent - term : exponent;
  }
  num = num - 1;
  // Calculate Mantissa
  for (int i = 9; i <= 31; i++){
	num = num * 2;
	ans[i] = num >= 1 ? 1 : 0;
	num = ans[i] == 1 ? num - 1 : num;
  }
  for (int i = 0; i < 32; i++) printf( i == 31 ? "%d\n" : "%d ", ans[i]);
  return 0;
}
