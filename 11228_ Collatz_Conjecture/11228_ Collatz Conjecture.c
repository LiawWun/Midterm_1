#include<stdio.h>
int CollatzConjecture(int num); 
int main(){
  int x, max = 0, step = 0;
  scanf("%d", &x);
  while (x != 1){
    step += 1;
    x = CollatzConjecture(x);
    max = x > max ? x : max;
  }
  printf("%d %d", step, max);
  return 0;
}
int CollatzConjecture(int num){
    return num % 2 == 0 ? num / 2 : 3 * num + 1;
}