
#include "Line2.h"




 Line2::Line2(int xlzdid, int zdid, int szid, int adjj, int xzid, int ysjl, int xldm, int sfty) {
     this->xlzdid=xlzdid;
     this->zdid=zdid;
     this->szid=szid;
     this->zdjj=adjj;
     this->xzid=xzid;
     this->ysjl=ysjl;
     this->xldm=xldm;
     this->sftk=sfty;
}


void Line2::set_xlzdid(int a) {
    xlzdid=a;
    return;
}


int Line2::get_xlzdid() {
    return xlzdid;
}


void Line2::set_zdid(int a) {
    zdid=a;
    return;
}


int Line2::get_zdid() {
    return zdid;
}


void Line2::set_szid(int a) {
    szid=a;
    return;
}


int Line2::get_szid() {
    return szid;
}


void Line2::set_zdjj(int a) {
    zdjj=a;
    return;
}


int Line2::get_zdjj() {
    return zdjj;
}


void Line2::set_xzid(int a) {
    xzid=a;
    return;
}


int Line2::get_xzid() {
    return xzid;
}


void Line2::set_ysjl(int a) {
    ysjl=a;
    return;
}

int Line2::get_ysjl() {
    return ysjl;
}


void Line2::set_xldm(int a) {
    xldm=a;
    return;
}


int Line2::get_xldm() {
    return xldm;
}


void Line2::set_sfty(int a) {
    sftk=a;
    return;
}


int Line2::get_sfty() {
    return sftk;
}

 Line2::~Line2() {

}
