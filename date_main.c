#include "date.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    DATE_T *d1, d2, d3; 
    d1 = malloc(sizeof(DATE_T));
    char format_str [30];

    init_date_1(d1);
    init_date(&d2, 30, 12, 1999);
    init_date(&d3, 1, 1, 2000);

    printf("\n");
    format_date(*d1, format_str);
    printf("d1: %s\n", format_str);
    format_date(d2, format_str);
    printf("d2: %s\n", format_str);
    format_date(d3, format_str);
    printf("d3: %s\n", format_str);

    printf("\n");
    printf("d1 < d2? %s\n" , date_less_than(*d1, d2) ? "TRUE" : "FALSE");
    printf("d2 < d3? %s\n" , date_less_than(d2, d3) ? "TRUE" : "FALSE");

    printf("\n");
    next_day(&d2);
    format_date(d2, format_str);
    printf("next day d2: %s\n", format_str);
    printf("d2 < d3? %s\n" , date_less_than(d2, d3) ? "TRUE" : "FALSE");
    printf("d2 = d3? %s\n" , date_equal(d2, d3) ? "TRUE" : "FALSE");
    printf("d2 > d3? %s\n" , date_less_than(d3, d2) ? "TRUE" : "FALSE");

    printf("\n");
    next_day(&d2);
    format_date(d2, format_str);
    printf("next day d2: %s\n", format_str);
    printf("d2 = d3? %s\n" , date_equal(d2, d3) ? "TRUE" : "FALSE");
    
    printf("\n");
    init_date(d1, 28, 2, 1529);
    format_date(*d1, format_str);
    printf("initialized d1 to %s\n", format_str);
    next_day(d1);
    format_date(*d1, format_str);
    printf("next day d1: %s\n", format_str);
    
    printf("\n");
    init_date(d1, 28, 2, 1460);
    format_date(*d1, format_str);
    printf("initialized d1 to %s\n", format_str);
    next_day(d1);
    format_date(*d1, format_str);
    printf("next day d1: %s\n", format_str);
    
    printf("\n");
    init_date(d1, 28, 2, 1700);
    format_date(*d1, format_str);
    printf("initialized d1 to %s\n", format_str);
    next_day(d1);
    format_date(*d1, format_str);
    printf("next day d1: %s\n", format_str);
    
    printf("\n");
    init_date(d1, 28, 2, 1600);
    format_date(*d1, format_str);
    printf("initialized d1 to %s\n", format_str);
    next_day(d1);
    format_date(*d1, format_str);
    printf("next day d1: %s\n", format_str);
    printf("\n");

    return EXIT_SUCCESS;
}
