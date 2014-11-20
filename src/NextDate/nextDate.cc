#include "nextDate.h"
#include <string>
#include <sstream>
using std::string;

bool isLeapYear(int year) {
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        return true;
    } else {
        return false;
    }
}

string handleFeb(int day, int year) {
    std::stringstream converter;

    if (day > 29) {
        converter << "Impossible date";
    } else if (29 == day) {
        if (isLeapYear(year) ) {
            converter << "3/1/" << year;
        } else {
            converter << "Impossible date";
        }
    } else if (28 == day) {
        if (isLeapYear(year) ) {
            converter << "2/29/" << year;
        } else {
            converter << "3/1/" << year;
        }
    } else {
        converter << "2/" << day + 1 << '/' << year;
    }

    return converter.str();
}

string handleDec(int day, int year) {
    std::stringstream converter;

    if (day < 31) {
        converter << "12/" << day + 1 << '/' << year;
    } else {
        if (2012 == year) {
            converter << "2012 is over.";
        } else {
            converter << "1/1/" << year + 1;
        }
    }

    return converter.str();
}

string handle30Days(int month, int day, int year) {
    std::stringstream converter;

    if (day > 30) {
        converter << "Impossible date";
    } else if (30 == day) {
        converter << month + 1 << "/1/" << year;
    } else {
        converter << month << '/' << day + 1 << '/' << year;
    }

    return converter.str();
}

string handle31Days(int month, int day, int year) {
    std::stringstream converter;

    if (31 == day) {
        converter << month + 1 << "/1/" << year;
    } else {
        converter << month << '/' << day + 1 << '/' << year;
    }

    return converter.str();
}

string nextDate(int month, int day, int year) {
    string next_date = "";

    if ((month < 1) || (month > 12) || (day < 1) || (day > 31) || (year < 1812) || (year > 2012)) {
        next_date = "Invalid input";
    } else if (2 == month) {
        next_date = handleFeb(day, year);
    } else if (12 == month) {
        next_date = handleDec(day, year);
    } else if ((3 == month) || (4 == month) || (6 == month) || (9 == month) || (11 == month)) {
        next_date = handle30Days(month, day, year);
    } else {
        next_date = handle31Days(month, day, year);
    }

    return next_date.c_str();
}
