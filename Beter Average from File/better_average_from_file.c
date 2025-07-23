#include <stdio.h>

#define TOTAL 1000 // Number of elements in the data set

int main(void)
{
    FILE *file = fopen("elephant_seal_data.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int data[TOTAL] = {0};
    long sum = 0;
    double avg = 0.0;
    int count = 0;

    while (count < TOTAL && fscanf(file, "%d", &data[count]) == 1) {
        sum += data[count];
        count++;
    }

    if (count < TOTAL) {
        printf("Warning: only %d values were read.\n", count);
    }

    fclose(file);

    if (count > 0) {
        avg = (double)sum / count;
        printf("The average weight for this population of elephant seals is: %.2lf\n", avg);
    } else {
        printf("No data read from file.\n");
    }

    return 0;
}