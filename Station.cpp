

#include "Station.h"



 Station::Station(int id, int lxid, string zdmc, int sfty, string cd, string elecd, string shortname) {
     this->id=id;
     this->lxid=lxid;
     this->zdmc=zdmc;
     this->sfty=sfty;
     this->cd=cd;
     this->elecd=elecd;
     this->shortname=shortname;
}


void Station::set_id(int a) {
    id=a;
    return;
}


int Station::get_id() {
    return id;
}


void Station::set_l(int a) {
    lxid=a;
    return;
}


int Station::get_l() {
    return lxid;
}

void Station::set_mc(string a) {
    zdmc=a;
    return;
}


string Station::get_mc() {
    return zdmc;
}


void Station::set_sf(int a) {
    sfty=a;
    return;
}


int Station::get_sf() {
    return sfty;
}


void Station::set_cd(string a) {
    cd=a;
    return;
}


string Station::get_cd() {
    return cd;
}


void Station::set_elecd(string a) {
    elecd=a;
    return;
}

string Station::get_elecd() {
    return elecd;
}

 Station::~Station() {

}
