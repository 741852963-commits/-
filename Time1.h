/**
 * Project Untitled
 */


#ifndef _TIME1_H
#define _TIME1_H

class Time {
public:
    

 Time(int h=-1, int m=-1);
    

void set_h(int a);
    
int get_h();
    

void set_m(int a);
    
int get_m();

~ Time();
private: 
    int h;
    int m;
};

#endif //_TIME1_H
