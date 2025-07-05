


#ifndef _DATE1_H
#define _DATE1_H

class Date1 {
public:
    
 Date1(int y=-1, int m=-1, int d=-1);
    

void set_y(int a);
    
int get_y();
    

void set_m(int a);
    
int get_m();
    

void set_d(int a);
    
int get_d();  
~ Date1();
private: 
    int year;
    int month;
    int day;
};

#endif //_DATE1_H
