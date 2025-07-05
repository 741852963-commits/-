


#include "Yuce.h"




/**
 * @param x
 * @param lc
 * @param id
 * @param y
 * @param m
 * @param d
 * @param h
 * @param m1
 * @param inf
 * @param outf
 */
Yuce::Yuce(int x, int lc, int id,  int d, int h,  int inf, int outf, string qd, string zd,int zkll) {
     this->xlbm=x;
     this->lcbm=lc;
     this->zdid=id;
     yxdate=d;
     yxti=h;
     liul.set_inf(inf);
     liul.set_outf(outf);
     this->zkll=zkll;
     this->qd=qd;
     this->zd=zd;

}


void Yuce::set_xl(int a) {
    xlbm=a;
    return;
}


int Yuce::get_xl() {
    return xlbm;
}


void Yuce::set_lcbm(int a) {
    lcbm=a;
    return;
}


int Yuce::get_lcbm() {
    return lcbm;
}


void Yuce::set_zdid(int a) {
    zdid=a;
    return;
}


int Yuce::get_zdid() {
    return zdid;
}


void Yuce::set_yxd(int a) {
    yxdate=a;
    return;
}


int Yuce::get_yxd() {
    return yxdate;
}


void Yuce::set_yxt(int h) {
    yxti=h;
    return;
}


int Yuce::get_yxt() {
    return yxti;
}

void Yuce::set_liu(int inf, int outf) {
    liul.set_outf(outf);
    liul.set_inf(inf);
    return;
}

PersonFlow Yuce::get_liu() {
    return liul;
}
void Yuce::set_zkll(int a){
    this->zkll=a;
    return ;
}
int Yuce::get_zkll(){
    return zkll;
}
void Yuce::set_qd(string a){
    this->qd=a;
    return ;
}
string Yuce::get_qd(){
    return qd;
}
void Yuce::set_zd(string a){
    zd=a;
    return ;
}
string Yuce::get_zd(){
    return zd;
}

 Yuce::~Yuce() {

}
