#include <stdio.h>
#include <string.h>
float calculate(float op1, float op2, char operation);

int main(){
  char math_exp[15];
  scanf("%s", &(math_exp[0]));
  float num_table[5];
  char operation_table[5];
  int i = 0, num_idx = 0, op_idx = 0, length = strlen(math_exp);
  // This part deal with the number inside ()
  while (i < length){
	if (math_exp[i] == '('){
	  float op1 = math_exp[i + 1] - '0';
	  float op2 = math_exp[i + 3] - '0';
	  char operation = math_exp[i + 2];
	  num_table[num_idx] = calculate(op1, op2, operation);
	  num_idx ++;
	  i += 5;
	}
	if (math_exp[i] == '+' || math_exp[i] == '-' || math_exp[i] == '*' || math_exp[i] == '/'){
	  operation_table[op_idx] = math_exp[i];
	  op_idx ++;
	  i ++;
	}
	if (math_exp[i] >= '0' && math_exp[i] <= '9'){
	  num_table[num_idx] = math_exp[i] - '0';
	  num_idx ++;
	  i ++;
	}
  }
  //Deal with "Multiply and divide first, then add and subtract"
  if (num_idx == 3){
	if (operation_table[0] == '*' || operation_table[0] == '/'){
	  printf("%.3f\n", calculate(calculate(num_table[0], num_table[1], operation_table[0]), num_table[2], operation_table[1]));
	}
	else if (operation_table[1] == '*' || operation_table[1] == '/'){
	  printf("%.3f\n", calculate(num_table[0], calculate(num_table[1], num_table[2], operation_table[1]), operation_table[0]));
	}
	else{ 
	  printf("%.3f\n", calculate(calculate(num_table[0], num_table[1], operation_table[0]), num_table[2], operation_table[1]));
	}
  }
  else{
	printf("%.3f\n", calculate(num_table[0], num_table[1], operation_table[0]));
  }
  return 0;
}

float calculate(float op1, float op2, char operation){
  switch (operation){
	case '+':
	  return op1 + op2;
	case '-':
	  return op1 - op2;
	case '*':
	  return op1 * op2;
	case '/':
	  return op1 / op2;
  }
}
