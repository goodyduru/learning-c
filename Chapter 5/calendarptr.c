#include <stdio.h>

static char (*daytab)[13] = (char [][13]){
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    if ( day > 31 || month > 12 || day < 1 || month < 1 ) {
        return -1;
    }
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    if ( day > 365 && leap == 0 || day > 366 ) {
        return 0;
    }
    return day;
}

void month_day(int year, int yearday, int* month, int* day) {
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
     if ( yearday > 365 && leap == 0 || yearday > 366 ) {
        return;
    }
    for ( i = 1; yearday > daytab[leap][i]; i++ ) {
        yearday -= daytab[leap][i];
    }
    *day = yearday;
    *month = i;
}

int main() {
    int month = 0, day = 0;
    month_day(2021, 265, &month, &day);
    printf("%d\t%d\n", day, month);
    printf("%d\n", day_of_year(2021, 12, 31));
}