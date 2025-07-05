

#include "PersonFlow.h"




 PersonFlow::PersonFlow(int inf, int outfl) {
     this->inflow=inf;
     this->outflow=outfl;
}


void PersonFlow::set_inf(int a) {
    inflow=a;
    return;
}

int PersonFlow::get_inf() {
    return inflow;
}


void PersonFlow::set_outf(int a) {
    outflow=a;
    return;
}


int PersonFlow::get_outf() {
    return outflow;
}

 PersonFlow::~PersonFlow() {

}
