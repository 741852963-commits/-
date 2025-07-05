


#include "Date1.h"




 Date1::Date1(int y, int m, int d) {
     year=y;
     month=m;
     day=d;
}


void Date1::set_y(int a) {
    year=a;
    return;
}


int Date1::get_y() {
    return year;
}

void Date1::set_m(int a) {
    month=a;
    return;
}


int Date1::get_m() {
    return month;
}

void Date1::set_d(int a) {
    day=a;
    return;
}


int Date1::get_d() {
    return day;
}

 Date1::~Date1() {

}
