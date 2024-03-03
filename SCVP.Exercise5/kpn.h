#include <iostream>
#include <systemc.h>

// Forward declaration of proc
template<int N=1, int M=1>
SC_MODULE(proc)
{
    public:

    sc_in<int> in[N];
    sc_out<int> out[M];
    int temp;

    SC_CTOR(proc) : temp(0)
    {
        SC_METHOD(fire);
        sensitive << in[N];
    }

    void fire()
    {
        for(int i=0;i<=N;i++)
        {
            temp = temp + in[i].read();
        }
        for(int i=0;i<=M;i++)
        {
            out[i].write(temp);
            cout << this->name() << ": " << out[i] << std::endl; // added missing semicolon and endl
        }
        temp = 0;
    }
};

#ifndef KPN_H
#define KPN_H

SC_MODULE(kpn)
{
public:
    // ADD THINGS HERE
    proc<2,1> Add;
    proc<1,3> Split;
    proc<1,1> Delay;

    sc_fifo<int> a;
    sc_fifo<int> b;
    sc_fifo<int> c;
    sc_fifo<int> d;
    sc_signal<int> e;
    

public:
    SC_CTOR(kpn) : a(10), b(10), c(10), d(10), e(0), Add("Add"), Split("Split"), Delay("Delay")  // : ADD THINGS HERE
    {
        
        b.write(1);
        c.write(0);
        Add.in[0].bind(a);
        Add.in[1].bind(c);
        Add.out[0].bind(b);

        Split.in[0].bind(b);
        Split.out[0].bind(a);
        Split.out[1].bind(d);
        Split.out[2].bind(e);

        Delay.in[0].bind(d);
        Delay.out[0].bind(c); 
        SC_THREAD(process);

    }
void process()
    {
        while(true)
        {
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            wait(10, SC_NS);
            Split.fire();
            wait(10, SC_NS);
            Delay.fire();
            wait(10, SC_NS);
            Add.fire();
            wait(10, SC_NS);
            sc_stop();
        }
    }
};

#endif // KPN_H
