void getMaxMin(char string_arr[][16], int size, int *min_idx, char **min, int *max_idx, char **max){	
  *min = strcmp(string_arr[0], string_arr[1]) < 0 ? string_arr[0] : string_arr[1];
  *min_idx = strcmp(string_arr[0], string_arr[1]) < 0 ? 0 : 1;
  *max = strcmp(string_arr[0], string_arr[1]) > 0 ? string_arr[0] : string_arr[1];
  *max_idx = strcmp(string_arr[0], string_arr[1]) > 0 ? 0 : 1;
  for (int i = 2; i < size; i++){
	*min = strcmp(*min, string_arr[i]) < 0 ? *min : string_arr[i];
	*min_idx = strcmp(*min, string_arr[i]) < 0 ? *min_idx : i;
	*max = strcmp(*max, string_arr[i]) > 0 ? *max : string_arr[i];
	*max_idx = strcmp(*max, string_arr[i]) > 0 ? *max_idx : i;
  }  
}