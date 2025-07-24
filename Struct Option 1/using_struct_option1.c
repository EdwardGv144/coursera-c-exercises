#include <stdio.h>
#include <math.h>

typedef enum month
{
    jan,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
} month;

typedef struct date
{
    month m;
    int d;
} date;

//Verifies if the date is out of the month, if so, increments month and restarts day count
void maxDate(date* day, int lastDate){
    if (day->d > lastDate){
        day->m = (day->m + 1) % 12;
        day->d = 1;
    }
}

//Moves date by one
void nextDay(date* day)
{
    day->d++;
    switch (day->m)
    {
    case jan:
        maxDate(day, 31);
        break;
    case feb:
        maxDate(day, 28);
        break;
    case mar:
        maxDate(day, 31);
        break;
    case apr:
        maxDate(day, 30);
        break;
    case may:
        maxDate(day, 31);
        break;
    case jun:
        maxDate(day, 30);
        break;
    case jul:
        maxDate(day, 31);
        break;
    case aug:
        maxDate(day, 31);
        break;
    case sep:
        maxDate(day, 30);
        break;
    case oct:
        maxDate(day, 31);
        break;
    case nov:
        maxDate(day, 30);
        break;
    case dec:
        maxDate(day, 31);
        break;
    default:
        printf("error"); //for debugging purposes
        break;
    }    
}

//Prints pure date (no need to receive date as pointer)
void printDate(date day)
{
    switch (day.m)
    {
    case jan:
        printf("January %d", day.d);
        break;
    case feb:
        printf("February %d", day.d);
        break;
    case mar:
        printf("March %d", day.d);
        break;
    case apr:
        printf("April %d", day.d);
        break;
    case may:
        printf("May %d", day.d);
        break;
    case jun:
        printf("June %d", day.d);
        break;
    case jul:
        printf("July %d", day.d);
        break;
    case aug:
        printf("August %d", day.d);
        break;
    case sep:
        printf("September %d", day.d);
        break;
    case oct:
        printf("October %d", day.d);
        break;
    case nov:
        printf("November %d", day.d);
        break;
    case dec:
        printf("December %d", day.d);
        break;
    default:
        printf("error"); //for debugging purposes
        break;
    }
}

//Prints a date and the date after it, receives the month and day
void printDateAndNextDay(month mon, int day){
    date currDate = {mon, day};

    printf("\n\nCurrent Date is:\n");
    printDate(currDate);
    printf("\nSo next day is:\n");
    nextDay(&currDate);
    printDate(currDate);
}

int main(void)
{
    printDateAndNextDay(feb, 28);
    printDateAndNextDay(mar, 14);
    printDateAndNextDay(oct, 31);
    printDateAndNextDay(dec, 31);
    return 0;
}