/**
 * Project Untitled
 */


#ifndef _YUCE_H
#define _YUCE_H
#include"PersonFlow.h"
#include<string>
using namespace std;

class Yuce {
public:
    

 Yuce(int x=-1, int lc=-1, int id=-1, int d=-1, int h=-1, int inf=-1, int outf=-1,string qd="",string zd="",int zkll=-1);

void set_xl(int a);
    
int get_xl();
    

void set_lcbm(int a);
    
int get_lcbm();
    

void set_zdid(int a);
    
int get_zdid();
    

void set_yxd(int a);
    
int get_yxd();
    

void set_yxt(int h);
    
int get_yxt();
    

void set_liu(int inf, int outf);
    
PersonFlow get_liu();
void set_zkll(int a);
int get_zkll();
void set_qd(string a);
string get_qd();
void set_zd(string a);
string get_zd();

    
~Yuce();
private: 
    int xlbm;
    int lcbm;
    int zdid;
    int yxdate;
    int yxti;
    PersonFlow liul;
    int zkll;
    string qd;
    string zd;
};

#endif //_YUCE_H
