#include<stdio.h>
int main(){
  int year1, month1, day1, year2, month2, day2, day_difference = 0;
  int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  scanf("%d %d %d", &year1, &month1, &day1);
  scanf("%d %d %d", &year2, &month2, &day2); 
  while( !(year1 == year2 && month1 == month2 && day1 == day2)){
    month_days[2] = (year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0) ? 29 : 28;
	day_difference ++;
	day1 ++;
	if(day1 > month_days[month1]){
	  day1 = 1;
	  month1 ++;
	}
	if(month1 > 12){
	  month1 = 1;
	  year1 ++;
	}
  }
  printf("%d", day_difference);
  return 0;
}
