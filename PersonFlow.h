

#ifndef _PERSONFLOW_H
#define _PERSONFLOW_H

class PersonFlow {
public:
    

 PersonFlow(int inf=-1, int outfl=-1);
    

void set_inf(int a);
    
int get_inf();
    

void set_outf(int a);
    
int get_outf();

    
~ PersonFlow();
private: 
    int inflow;
    int outflow;
};

#endif //_PERSONFLOW_H
