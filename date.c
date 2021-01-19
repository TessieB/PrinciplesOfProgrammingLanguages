#include "date.h"
#include <stdio.h>
#include <time.h>


// Initializes the date with the values for day, month, and year that 
// are passed in through the parameter
void init_date (DATE_T *date, int day, int month, int year){
    date->day = day;
    date->month = month;
    date->year = year;
}


// Initializes the date with today's values for day, month, and year
void init_date_1 (DATE_T *date){
    time_t curr_time = time (NULL);
    struct tm local_date = *localtime (&curr_time);
    date->day = local_date.tm_mday;
    date->month = local_date.tm_mon + 1;
    date->year = local_date.tm_year + 1900;
}


// Checks if the two dates passed in are the same and returns 1 if this is true
int date_equal (DATE_T date1, DATE_T date2){
    if (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year){
        return 1;
    }
    return 0;
}


// Checks if the first date passed in comes before the second date and returns 1 if true
int date_less_than (DATE_T date1, DATE_T date2){
    if (date1.year < date2.year){
        return 1;
    }
    else if (date1.year == date2.year && date1.month < date2.month){
        return 1;
    }
    else if (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day ){
        return 1;
    }
    return 0;
}


// Returns the string name of the month passed in
static char *month_str (int month){
    switch(month){
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "unknown";
    }
}


// Formats the date on a string so that the string equals Month Day, Year
void format_date (DATE_T date, char *str){
    sprintf(str, "%s %d, %d", month_str(date.month), date.day, date.year);
}


// Returns 1 if the year passed in is a leap year and 0 if it is not
static int leap_year (int year){
    if (year % 4 == 0){
        if (year % 100 == 0){
            if (year % 400 == 0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}


// Returns the number of days in the month passed in
static int month_length (int month, int leap){
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2){
        if(leap){
            return numDays[month - 1] + 1;
        }
        else{
            return numDays[month - 1];
        }
    }
    else{
        return numDays[month - 1];
    }
}


// Sets the date passed in equal to the next date
void next_day (DATE_T *date){
    int leap = leap_year(date->year);
    if (date->month == 12 && date->day == month_length(date->month, leap)){
        date->day = 1;
        date->month = 1;
        date->year = date->year + 1;
    }
    else if (date->day == month_length(date->month, leap)){
        date->day = 1;
        date->month = date->month + 1;
    }
    else{
        date->day = date->day + 1;
    }
}
