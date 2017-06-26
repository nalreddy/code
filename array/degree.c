#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

int degreeOfArray(int arr_size, int* arr) {

    int *visited =  (int *) malloc(sizeof(int) * arr_size);
    int i = 0, j = 0;
    int temp = 0, freq = 0, max = 0;
    int start = 0, end = 0;
    int len = INT_MAX;
  
    memset(visited,0,arr_size);
    for(i = 0; i < arr_size; i++) {
	 freq = 1;
         temp = arr[i];
         visited[i] = 1;
         start = i;
         end = start + 1;
        for( j = i+1 ; j < arr_size; j++){
              if(temp == arr[j] && !visited[j]) {
                 visited[j] = 1;
                 freq++;
                 end = j;
		 printf("i = %d and j = %d and arr[i] = %d and arr[j] =%d\n",i,j,arr[i],arr[j]);
              }
        }
        
        if(freq >= max && (len > (end - start))) {
            max = freq;
	    printf("start = %d and end = %d \n", start,end);
            len = end - start + 1;
        }
    }
    free(visited);
    return len;
}

int main()
{
  int arr[] = {1,2,2,3,1};

  printf("degree = %d\n",degreeOfArray(3,arr));

 return 0;
}
