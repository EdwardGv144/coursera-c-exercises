/* Compute a better average. */

#include <stdio.h>

int main(void) {
    int count = 0;
    double value;
    double running_avg = 0.0;
    double naive_avg;
    double sum = 0.0;

    printf("%5s%17s%17s%17s\n%5s%17s%17s%17s\n\n", 
        "Count", "Item", "Average", "Naive avg",
        "_____", "____", "_______", "_________");

    while (scanf("%lf", &value) == 1) {
        ++count;
        running_avg += (value - running_avg) / count;
        naive_avg = sum / count;

        printf("%5d%17e%17e%17e\n", count, value, running_avg, naive_avg);

        sum += value;
    }

    return 0;
}
