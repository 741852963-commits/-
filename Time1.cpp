

#include "Time1.h"





 Time::Time(int h, int m) {
     this->h=h;
     this->m=m;
}


void Time::set_h(int a) {
    h=a;
    return;
}


int Time::get_h() {
    return h;
}


void Time::set_m(int a) {
    m=a;
    return ;
}


int Time::get_m() {
    return m;
}

 Time::~Time() {

}
