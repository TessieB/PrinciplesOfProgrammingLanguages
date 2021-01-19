#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date{
    private:
        int day, month, year;
        string monthStr (void);
        bool leapYear (void);
        int monthLength (void);
    public:
        Date (void);
        Date (int, int, int);
        void set (int, int, int);
        bool equals (Date);
        bool operator== (Date);
        bool lessThan (Date);
        bool operator< (Date);
        bool operator> (Date);
        void format (string &str);
        void nextDay (void);
        void operator++ (void);
        void operator++ (int dummy);
};

#endif /* DATE_H */