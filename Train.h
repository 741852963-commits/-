

#ifndef _TRAIN_H
#define _TRAIN_H
#include<string>
using namespace std;
class Train {
public:
    

 Train(string bm="", string dm="",  int yn=-1);
    

void set_b(string a);
    
string get_b();
    

void set_d(string a);
    
string get_d();
    
void set_yn(int a);
    
int get_yn();

    
~ Train();
private: 
    string bm;
    string dm;
    int yn;
};

#endif //_TRAIN_H
