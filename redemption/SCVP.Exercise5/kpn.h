#ifndef KPN_H
#define KPN_H
#include <iostream>
#include <systemc.h>
using namespace std;
SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    
    sc_fifo<unsigned int> a;
    sc_fifo<unsigned int> b;
    sc_fifo<unsigned int> c;
    sc_fifo<unsigned int> d;
    int count;
    sc_signal<unsigned int> e;
public:
    SC_CTOR(kpn) : a(10), b(10), c(10), d(10), e("e"), count(0)// : ADD THINGS HERE
    {
        // ADD THINGS HERE

        b.write(1);
        c.write(0);
        

        
        SC_THREAD(Split);
        SC_THREAD(Delay);
        SC_THREAD(Add);
        
        


    }
    void Split();
    void Delay();
    void Add();
   
    

};

#endif // KPN_H
