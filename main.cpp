#include <fstream>
#include <iostream>
#include <string>
#include <ctime>   
#include "time.h"
using namespace std;

Time& getCurrentTime();

int main() {

    ofstream ofs;
    ofs.open("schedule.txt");
    
    Time time = getCurrentTime();


    for(int i = 0; i < 20; i++){
        ofs << time << " - ";
        time.add_minutes(52);
        ofs << time << endl;
        time.add_minutes(17);
    }
    
    return 0;
}

Time& getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hours, minutes;
    hours = ltm->tm_hour;
    minutes = ltm->tm_min;
    Time *t = new Time(hours, minutes);
    return *t;
}



