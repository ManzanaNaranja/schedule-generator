#ifndef TIME_H
#define TIME_H

#include <ostream>
#include <string>
using namespace std;

class Time {
    public:
        Time(int=0, int=0);
        int get_hours() const;
        int get_minutes() const;
        void set_hours(int);
        void set_minutes(int);
        void add_minutes(int);
        void print() const;
        string str() const;
        friend ostream& operator<<(ostream&, const Time&);

    private:
        int hours;
        int minutes;
        void fix_overflow();

};

#endif