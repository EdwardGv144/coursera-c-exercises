#include <stdio.h>
#include <math.h>

int main(void){

    double x = 2; //Start with an out of bounds value to enter the loop
    double result = 0;

    while((x < 0)||(x > 1)){
        printf("Input a number betwen 0 and 1: ");
        scanf("%lf", &x);
        if((x < 0)||(x > 1)){
            printf("\nThe number you entered is not within the range, try again!\n");
        }
    }

    result = sin(x);

    printf("\nThe sine of %.8lf is %.8lf\n", x, result);

    return 0;
}