#include<stdio.h>
float ConvertToFloat(int *reg){
	// Sign
	int sign = *reg;
	reg ++;
	// Calculate Exponent
	int exponent = -127;
	int term = 128;
	for (int i = 0; i < 8; i++, reg++, term /= 2) exponent += *reg * term;
  // Calculate Significant
	float significant = 1;
	float j = 0.5;
	for (int i = 9; i <= 31; i++, reg++, j /= 2) significant += *reg * j;
	// Calculate the result
	float output = sign == 0 ? 1 : -1;
	if (exponent > 0) for (int i = 1; i <= exponent; i++, output *= 2);
	else if (exponent < 0) for (int i = -1; i >= exponent; i--, output /= 2);
	output *= significant;
  return output;
}

float ConvertToFloat_NonPointer(int reg[]){
	// Sign
	int sign = reg[0];
	// Calculate Exponent
	int exponent = -127;
	for (int i = 8, j = 1; i >= 1; i--, j *= 2)	exponent += reg[i] * j;
	// Calculate Significant
	float significant = 1;
	float j = 0.5;
	for (int i = 9; i <= 31; i ++, j /= 2) significant += reg[i] * j;
	// Calculate the result
	float output = sign == 0 ? 1 : -1;
	if (exponent > 0) for (int i = 1; i <= exponent; i++, output *= 2);
	else if (exponent < 0) for (int i = -1; i >= exponent; i--, output /= 2);
	return  output;
}


