#inlude<stdio.h>
int main(){
  int arr_size, bm;
  scanf("%d", &arr_size);
  int answer[arr_size];
  int invalid = 0;
  for (int i = 0; i < arr_size; i++) answer[i] = 0;
    for (int m = 1; scanf("%d", &bm) != EOF; m++){
	  if ( bm > arr_size - m ){
        invalid = 1;
      break;
		}		
		int count_zero = 0;
		for (int i = 0; i < arr_size; i++){
			if ( answer[i] == 0 ) count_zero ++;
			if ( count_zero == bm + 1 ){
			  answer[i] = m;
				break;
			}
		}
	}
	if( invalid == 1){
		printf("No answer");
	}
	else{
	  for (int j = 0; j < arr_size; j++ ) printf( j == arr_size - 1 ? "%d" : "%d ", answer[j]);
	}
  return 0;
}
