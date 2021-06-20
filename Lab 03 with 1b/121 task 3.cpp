#include <iostream>
using namespace std;

class Time {
private:
    unsigned int hour, minute, second;
public:
    Time() : hour(0), minute(0), second(0) {

    }
    int hours() {
        return hour;
    }
    int minutes() {
        return minute;
    }
    int seconds() {
        return second;
    }
    void reset(int h, int m, int s) {
        if(h < 0 || m < 0 || s < 0 || h >= 24 || m >= 60 || s >= 60) {
            cout<<"Error: invalid time input"<<endl;
            return;
        }
        hour = h;
        minute = m;
        second = s;
    }
    void advance(int h, int m, int s) {
        if((hour+h < 0) || (minute+m < 0) || (second+s < 0)) {
            cout<<"Error: invalid time input"<<endl;
            return;
        }
        second = second + s;
        minute = minute + m + second/60;
        second = second % 60;
        hour = hour + h + minute/60;
        minute = minute % 60;
        hour = hour % 24;
    }
    void print() {
        cout<<"Current time is "<<hour<<" hours "<<minute<<" minutes "<<second<<" seconds."<<endl;
    }
};

int main(){
    Time t;
    t.reset(16, 51, 30);
    t.print();
    t.advance(8, 0, 60);
    t.print();
}
