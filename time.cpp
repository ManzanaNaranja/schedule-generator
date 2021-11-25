#include "time.h"
#include <iostream>

Time::Time(int hrs, int mins) {
    hours = hrs;
    minutes = mins;
    fix_overflow();
}

int Time::get_hours() const {
    return hours;
}

int Time::get_minutes() const {
    return minutes;
}

void Time::set_hours(int h) {
    if(h <= 23 && h >= 0) {
        hours = h;
    }
}

void Time::set_minutes(int m) {
    if(m >= 0 && m <= 59) {
        minutes = m;
    }
}

void Time::add_minutes(int m) {
    minutes += m;
    fix_overflow();
}

ostream& operator<<(ostream& os, const Time &t) {
    os << t.str();
    return os;
}

void Time::print() const {
    cout << str();
}

string Time::str() const {
   string strmins = to_string(minutes);
   string suffix = "AM";
   string strhrs;
   if(hours > 12) {
       suffix = "PM";
       strhrs = to_string(hours-12);
   } else if(hours == 0) {
       strhrs = "12";
   } else {
      strhrs = to_string(hours);
   }
   if(minutes < 10) {
       strmins = "0" + strmins;
   }
   return strhrs + ":" + strmins + " " + suffix;
}

void Time::fix_overflow() {  
    while(minutes >= 60) {
        minutes -= 60;
        hours += 1;
    }
    while(hours >= 24) {
        hours -= 24;
    }
}