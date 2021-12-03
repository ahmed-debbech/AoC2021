#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Hello World\n");
  FILE * f = fopen("input", "r");
  if(f == NULL){
    return 1;
  }
  int num = 0;
  int arr[2000];
  int counter = 0;
  while(!feof(f)){
    fscanf(f, "%d\n", &num);
    arr[counter] = num;
    counter++;
  }

  int size = counter-1;
  counter = 0;
  int still = 1;
  int arr2[2000];
  int counter2 = 0;
  while(still == 1){
    if(counter + 2 > size){
        still = 0;
    }else{
      int sum =  arr[counter] + arr[counter+1] + arr[counter+2];
      arr2[counter2] = sum;
      counter2++;
    }
    counter++;
  }
  int y;
  for(y=0; y<=counter2-1; y++){
   printf("second array[%d] : %d\n", y, arr2[y]);
  }
  int i;
  int prev = 1;
  int total = 0;
  for(i = 0; i<=counter2-2; i++){
    if(arr2[i] > prev){
      total++;
    }
    prev = arr2[i];
  }
  printf("RESULT: %d\n", total);
  return 0;
}
