#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    int arraySize = 0, max = 0;
    int *data;
    double avg = 0.0;

    // Open input file
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read first number to determine array size
    if (fscanf(file, "%d", &arraySize) != 1 || arraySize <= 0) {
        printf("Invalid or missing array size in file.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory
    data = (int *)malloc(arraySize * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Read values into array, calculate avg and max
    for (int i = 0; i < arraySize; i++) {
        if (fscanf(file, "%d", &data[i]) != 1) {
            printf("Not enough integers for given array size.\n");
            free(data);
            fclose(file);
            return 1;
        }

        avg += data[i];
        if (data[i] > max) max = data[i];
    }

    avg /= arraySize;
    fclose(file);

    // Print to screen
    printf("Array of integers:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", data[i]);
    }
    printf("\nAverage: %.3lf", avg);
    printf("\nMaximum: %d\n", max);

    // Write to output file
    file = fopen("answer.txt", "w");
    if (file == NULL) {
        printf("Error opening output file.\n");
        free(data);
        return 1;
    }

    fprintf(file, "Array of integers:\n");
    for (int i = 0; i < arraySize; i++) {
        fprintf(file, "%d ", data[i]);
    }
    fprintf(file, "\nAverage: %.3lf", avg);
    fprintf(file, "\nMaximum: %d", max);

    fclose(file);
    free(data);

    return 0;
}
