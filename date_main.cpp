#include "date.hpp"
#include <iostream>
using namespace std;


string true_or_false(bool a){
    if (a){
        return "TRUE";
    }
    else{
        return "FALSE";
    }
}

int main(){

    // Creates three date objects with either 
    // the current date or a set date
    Date *d1 = new Date();
    Date d2 (30, 12, 1999);
    Date d3 (1, 1, 2000);
    string str;


    // Formats the three date objects and prints them
    cout << "\n";
    d1->format(str);
    cout << str << "\n";
    d2.format(str);
    cout << str << "\n";
    d3.format(str);
    cout << str << "\n";


    // Calls the lessThan method to see if 
    // d1 is less than d2 and d2 is less than d3
    cout << "\n";
    cout << "d1 < d2? " << true_or_false(d1->lessThan(d2)) << "\n";
    cout << "d2 < d3? " << true_or_false(d2.lessThan(d3)) << "\n";


    // Calls nextDay method to increment the date by one day and formats that string, then calls
    // the overloaded <, overloaded ==, and overloaded > methods
    // to see if d2 is less than, equal to, or greater than d3
    cout << "\n";
    d2.nextDay();
    d2.format(str);
    cout << "next day d2: " << str << "\n";
    cout << "d2 < d3? " << true_or_false(d2 < d3) << "\n";
    cout << "d2 = d3? " << true_or_false(d2 == d3) << "\n";
    cout << "d2 > d3? " << true_or_false(d2 > d3) << "\n";


    // Calls the overloaded postfix increment method to set
    // d2 equal to the second date and checks if d2 equals d3
    cout << "\n";
    d2++;
    d2.format(str);
    cout << "next day d2: " << str << "\n";
    cout << "d2 = d3? " << true_or_false(d2 == d3) << "\n";


    // Sets d1 equal to February 2, 1529 with the set method and
    // then calls the nextDay method to increment d1 by one day
    cout << "\n";
    d1->set(28, 2, 1529);
    d1->format(str);
    cout << "initialized d1 to " << str << "\n";
    d1->nextDay();
    d1->format(str);
    cout << "next day d1: " << str << "\n";


    // Sets d1 equal to February 2, 1460 with the set method and
    // then calls the overloaded prefix increment method to increment d1 by one day
    cout << "\n";
    d1->set(28, 2, 1460);
    d1->format(str);
    cout << "initialized d1 to " << str << "\n";
    ++*d1;
    d1->format(str);
    cout << "next day d1: " << str << "\n";


    // Sets d1 equal to February 2, 1700 with the set method and
    // then calls the overloaded prefix increment method to increment d1 by one day
    cout << "\n";
    d1->set(28, 2, 1700);
    d1->format(str);
    cout << "initialized d1 to " << str << "\n";
    ++*d1;
    d1->format(str);
    cout << "next day d1: " << str << "\n";


    // Sets d1 equal to February 2, 1600 with the set method and
    // then calls the overloaded postfix increment method to increment d1 by one day
    cout << "\n";
    d1->set(28, 2, 1600);
    d1->format(str);
    cout << "initialized d1 to " << str << "\n";
    (*d1)++;
    d1->format(str);
    cout << "next day d1: " << str << "\n";

}