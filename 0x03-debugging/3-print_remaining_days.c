#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/

void print_remaining_days(int month, int day, int year)
{
    int days = 0;

    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
        return;
    }

    switch (month)
    {
        case 12:
            days += 30; /* Nov */
        case 11:
            days += 31; /* Oct */
        case 10:
            days += 30; /* Sep */
        case 9:
            days += 31; /* Aug */
        case 8:
            days += 31; /* Jul */
        case 7:
            days += 30; /* Jun */
        case 6:
            days += 31; /* May */
        case 5:
            days += 30; /* Apr */
        case 4:
            days += 31; /* Mar */
        case 3:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                days += 29;
            else
                days += 28; /* Feb */
        case 2:
            days += 31; /* Jan */
            break;
        case 1:
            break;
        default:
            printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
            return;
    }

    if (day < 1 || day > days)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
        return;
    }

    days -= day;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        printf("Day of the year: %d\nRemaining days: %d\n", 31 + 29 + days, days);
    else
        printf("Day of the year: %d\nRemaining days: %d\n", 31 + 28 + days, days);
}