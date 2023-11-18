#include<stdio.h>
int getCommand(char code[]);
int main(){
  int x[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  char codes[100][15];
  int count = 0;
  for (int i = 0; scanf("%s", &(codes[i][0])) != EOF; i++, count++){}
  int pc = 0, x_src1 = 0, x_src2 = 0, x_d = 0, constant = 0, end_token = 0;
  while(1){
	switch (getCommand(codes[pc])){
	  case 1: // addi
		x_d = codes[pc][6] - '0';
		x_src1 = codes[pc][9] - '0';
		constant = codes[pc][11] == '-' ? -(codes[pc][12] - '0') : codes[pc][11] - '0';
		pc ++;
		x[x_d] = x[x_src1] + constant;
		break;
	  case 2: // add
		x_d = codes[pc][5] - '0';
		x_src1 = codes[pc][8] - '0';
		x_src2 = codes[pc][11] - '0';
		pc ++;
		x[x_d] = x[x_src1] + x[x_src2];
		break;
	  case 3: // sub
		x_d = codes[pc][5] - '0';
		x_src1 = codes[pc][8] - '0';
		x_src2 = codes[pc][11] - '0';
		pc ++;			
		x[x_d] = x[x_src1] - x[x_src2];
		break;
	  case 4: // beq
		x_src1 = codes[pc][5] - '0';
		x_src2 = codes[pc][8] - '0';
		constant = codes[pc][10] == '-' ? -(codes[pc][11] - '0') : codes[pc][10] - '0';			
		pc = (x[x_src1] == x[x_src2]) ? pc + constant : pc + 1;
		break;
	  case 5: // bge
		x_src1 = codes[pc][5] - '0';
		x_src2 = codes[pc][8] - '0';
		constant = codes[pc][10] == '-' ? -(codes[pc][11] - '0') : codes[pc][10] - '0';
		pc = (x[x_src1] >= x[x_src2]) ? pc + constant : pc + 1;
		break;
	  case 6: // end
		end_token = 1;
		break;
	}
	if (end_token == 1) break;
  }
  for (int i = 0; i < 8; i++) printf( i == 7 ? "%d\n" : "%d " , x[i]);
  return 0;
}

int getCommand(char code[]){
	if (code[0] == 'a' && code[1] == 'd' && code[2] == 'd'){return code[3] == 'i' ? 1 : 2;}
	else if (code[0] == 's' && code[1] == 'u' && code[2] == 'b'){return 3;}
	else if (code[0] == 'b' && code[1] == 'e' && code[2] == 'q'){ return 4;}
	else if (code[0] == 'b' && code[1] == 'g' && code[2] == 'e'){return 5;}
	else {return 6;}
}

