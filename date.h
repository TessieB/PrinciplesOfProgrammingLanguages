#ifndef DATE_H
#define DATE_H

typedef struct{
    int day, month, year;
} DATE_T;

void init_date (DATE_T *date, int day, int month, int year);

void init_date_1 (DATE_T *date);

int date_equal (DATE_T date1, DATE_T date2);

int date_less_than (DATE_T date1, DATE_T date2);

static char *month_str (int month);

void format_date (DATE_T date, char *str);

static int leap_year (int year);

static int month_length (int month, int leap);

void next_day (DATE_T *date);

#endif /* DATE_H */
