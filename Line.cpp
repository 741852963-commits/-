


#include "Line.h"
#include"Line2.h"


 Line::Line(int bm) {
     this->bm=bm;

}


void Line::set_b(int a) {
    bm=a;
    return;
}


int Line::get_b() {
    return bm;
}


void Line::set_s(vector<Line2> a) {
    sj=a;
    return;
}


vector<Line2> Line::get_s() {
    return this->sj;
}
void Line::set_sj( const Line2 &a){
      sj.push_back(a);
    return ;
}

 Line::~Line() {

}
