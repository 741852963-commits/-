


#ifndef _LINE2_H
#define _LINE2_H

class Line2 {
public:
    

 Line2(int xlzdid=-1, int zdid=-1, int szid=-1, int adjj=-1, int xzid=-1, int ysjl=-1, int xldm=-1, int sfty=-1);
    

void set_xlzdid(int a);
    
int get_xlzdid();

void set_zdid(int a);
    
int get_zdid();

void set_szid(int a);
    
int get_szid();
    

void set_zdjj(int a);
    
int get_zdjj();
    

void set_xzid(int a);
    
int get_xzid();
    

void set_ysjl(int a);
    
int get_ysjl();
    

void set_xldm(int a);
    
int get_xldm();
    
void set_sfty(int a);
    
int get_sfty();

    
~ Line2();
private: 
    int xlzdid;
    int zdid;
    int szid;
    int zdjj;
    int xzid;
    int ysjl;
    int xldm;
    int sftk;
};

#endif //_LINE2_H
