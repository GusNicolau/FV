#include "State.h"

State* State::pinstance=0;

State* State::Instance(){
    if(pinstance==0){
        pinstance=new State();
    }
    return pinstance;
}

