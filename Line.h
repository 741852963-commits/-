


#ifndef _LINE_H
#define _LINE_H
#include"Line2.h"
#include<vector>
using namespace std;
class Line {
private:
    int bm;
    vector<Line2> sj;
public:
    
 Line(int bm=0);
    

void set_b(int a);
    
int get_b();
    

void set_s(vector<Line2> a);
vector<Line2> get_s();
void set_sj(const Line2 &a);
    
~ Line();

};

#endif //_LINE_H
