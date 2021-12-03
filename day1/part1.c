#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f = fopen("input", "r");
    if(f == NULL){
        return 1;
    }
    int prev = -1;
    int now = 0;
    int inc = 0;
    int start = 0;
    while(!feof(f)){
        fscanf(f, "%d\n", &now);
        if(start == 1){
            if(now > prev){
                inc++;
            }
        }
        start = 1;
        prev = now;
        printf("%d\n", now);
    }
    printf("RESULT: %d\n" , inc);
    return 0;
}