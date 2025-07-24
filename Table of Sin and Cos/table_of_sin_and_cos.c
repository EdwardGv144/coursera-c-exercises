#include <stdio.h>
#include <math.h>

int main(void){

    printf("  ________ ________\n");
    printf(" |   sin  |   cos  |\n");
    for(float i = 0.1; i <= 1; i += 0.1){
        printf(" -------------------\n");
        printf(" | %.4lf | %.4lf |\n", sin(i), cos(i));
    }
    printf(" -------------------\n");

    return 0;
}