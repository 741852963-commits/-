


#include "Train.h"





 Train::Train(string bm, string dm, int yn) {
     this->bm=bm;
     this->dm=dm;
     this->yn=yn;
}


void Train::set_b(string a) {
    bm=a;
    return;
}


string Train::get_b() {
    return bm;
}


void Train::set_d(string a) {
    dm=a;
    return;
}


string Train::get_d() {
    return dm;
}


void Train::set_yn(int a) {
    yn=a;
    return;
}


int Train::get_yn() {
    return yn;
}

 Train::~Train() {

}
