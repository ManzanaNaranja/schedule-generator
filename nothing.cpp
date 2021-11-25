#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void outputTime(ostream&, int, int);

int main() {

    ofstream ofs;
    ofs.open("schedule.txt");
    cout << "Enter start time: [x:xx] ";
    int hours, minutes;
    cin >> hours;
    cin.ignore();
    cin >> minutes;
    
    while(hours < 12) {
        outputTime(ofs, hours, minutes);
        ofs << " - ";
        minutes += 52;
        if(minutes >= 60) {
            minutes -= 60;
            hours += 1;
        }
        outputTime(ofs, hours, minutes);
        minutes += 17;
        if(minutes >= 60) {
            minutes -= 60;
            hours += 1;
        }
        ofs << endl;

    }
    return 0;
}

void outputTime(ostream &o, int hrs, int mins) {
    string strmins = to_string(mins);
    if(mins < 10) strmins = "0" + strmins;
    o << hrs << ":" << strmins;
}

