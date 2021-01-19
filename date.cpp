#include "date.hpp"
#include <iostream>
#include <time.h>
using namespace std;


// Initializes date object with current date
Date :: Date (void){
    time_t currTime = time (NULL);
    struct tm local_date = *localtime (&currTime);
    this->day = local_date.tm_mday;
    this->month = local_date.tm_mon + 1;
    this->year = local_date.tm_year + 1900;
}


// Initializes date object with the day, month, and year parameters passed in
Date :: Date (int day, int month, int year){
    set(day, month, year);
}


// Sets the date object with the day, month, and year parameters passed in
void Date :: set (int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}


// Checks if the date passed in equals this object's date and returns true if this is the case
bool Date :: equals (Date date){
    if (this->day == date.day && this->month == date.month && this->year == date.year){
        return true;
    }
    else{
        return false;
    }
}


// Overloads the == operator so that == checks whether or not two dates are equal and returns true if so
bool Date :: operator== (Date date){
    return equals(date);
}


// Checks if this object's date is less than the date passed in and returns true if this is the case
bool Date :: lessThan (Date date){
    if (this->year < date.year){
        return true;
    }
    else if (this->year == date.year && this->month < date.month){
        return true;
    }
    else if (this->year == date.year && this->month == date.month && this->day < date.day ){
        return true;
    }
    return false;
}


// Overloads the < operator so that < checks whether or not the first date
// is less than the second date and returns true if so
bool Date :: operator< (Date date){
    return lessThan(date);
}


// Overloads the > operator so that > checks whether or not the first date
// is greater than the second date and returns true if so
bool Date :: operator> (Date date){
    if (equals(date)){
        return false;
    }
    else if (lessThan(date)){
        return false;
    }
    else{
        return true;
    }
}


// Returns the string name of this date's month or "unknown" if the month is out of range
string Date :: monthStr (void){
    switch(this->month){
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


// Formats this date in a string str as month day, year
void Date :: format (string &str){
    str = monthStr() + " " + to_string(this->day) + ", " + to_string(this->year);
}


// Checks if this date occurs during a leap year and returns true if so
bool Date :: leapYear (void){
    if (this->year % 4 == 0){
        if (this->year % 100 == 0){
            if (this->year % 400 == 0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


// Returns the number of days in this date's month
int Date :: monthLength (void){
    int numDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2){
        if(leapYear()){
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


// Sets this date equal to the next day
void Date :: nextDay (void){
    if (this->month == 12 && this->day == monthLength()){
        this->day = 1;
        this->month = 1;
        this->year++;
    }
    else if (this->day == monthLength()){
        this->day = 1;
        this->month ++;
    }
    else{
        this->day++;
    }
}


// Overloads the prefix increment operator so that ++ increments this
// date by one day
void Date :: operator++ (void){
    nextDay();
}


// Overloads the postfix increment operator so that ++ increments this
// date by one day
void Date :: operator++ (int dummy){
    nextDay();
}