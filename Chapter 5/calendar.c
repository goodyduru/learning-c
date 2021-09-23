#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    char *p;
    if ( day > 31 || month > 12 || day < 1 || month < 1 ) {
        return -1;
    }
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = &daytab[leap][1];
    for (i = 1; i < month; i++) {
        day += *p;
        p++;
    }

    if ( day > 365 && leap == 0 || day > 366 ) {
        return 0;
    }
    return day;
}

void month_day(int year, int yearday, int* month, int* day) {
    int i, leap;
    char *p;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
     if ( yearday > 365 && leap == 0 || yearday > 366 ) {
        return;
    }
    p = &daytab[leap][1];
    for ( i = 1; yearday > *p; i++ ) {
        yearday -= *p;
        p++;
    }
    *day = yearday;
    *month = i;
}

int main(int argc, char *argv[]) {
    int month, day;
    if ( argc < 2 || (strcmp(argv[1], "md") != 0 && strcmp(argv[1], "doy") != 0) ) {
        printf("Illegal option\n");
        return 0;
    }

    if ( (strcmp(argv[1], "md") == 0 && argc < 4) ||  (strcmp(argv[1], "doy") == 0 && argc < 5) ) {
        printf("Incomplete options\n");
        return 0;
    }
    if ( strcmp(argv[1], "md") == 0 ) {
        month = 0;
        day = 0;
        month_day(atoi(argv[2]), atoi(argv[3]), &month, &day);
        printf("%d\t%d\n", day, month);
        return 0;
    }
    else {
        printf("%d\n", day_of_year(atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
        return 0;
    }
}