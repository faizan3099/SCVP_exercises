#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

enum base {Start, G, GA, GAA, GAAG};

SC_MODULE(stateMachine)
{
    
    sc_in<char> input;
    sc_in<bool> clk;

    int currentState;
    int count;
    int counter;
    SC_CTOR(stateMachine) : currentState(Start) , count(0), counter(0)
    {
        SC_METHOD(process);
        sensitive << clk.pos();
        dont_initialize();
        
    } 
    void process();
};

#endif // STATE_MACHINE_H


