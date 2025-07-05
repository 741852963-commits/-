


#ifndef _STATION_H
#define _STATION_H
#include<string>
using namespace std;
class Station {
public:
    

 Station(int id=-1, int lxid=-1, string zdmc="", int sfty=-1, string cd="", string elecd="", string shortname="");
    

void set_id(int a);
    
int get_id();
    

void set_l(int a);
    
int get_l();
    

void set_mc(string a);
    
string get_mc();
    

void set_sf(int a);
    
int get_sf();
    
void set_cd(string a);
    
string get_cd();
    

void set_elecd(string a);
    
string get_elecd();

    
~ Station();
private: 
    int id;
    int lxid;
    string zdmc;
    int sfty;
    string cd;
    string elecd;
    string shortname;
};

#endif //_STATION_H
