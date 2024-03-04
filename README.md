Sc_module(name) 
Sc_in<>input;
Sc_out<>output;

Sc_signal<>h1; // here define as many helping signals as you want

Sc_ctor(name)
Sc_method(process1);
Sensitive << clk.pos() <<  reset;
Sc_method(process2);
Sensitive << h1 …..;


Void (process1) //combinational 
Output = h1 + ……


Void (process2)
If (reset)
h1 = 0 //output of each register goes to 0

Else if (clock edge)
h1 = input // all outputs of the registers equal to the inputs
…..
