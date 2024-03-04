#include <unistd.h>
#include <systemc.h>
#include <iostream>
#include "kpn.h"

// ADD THINGS HERE
void kpn :: Split()
{   
    while(count<=10)
    {   
        unsigned int split= b.read();
        a.write(split);
        d.write(split);
        e.write(split);
       
        std::cout << "The " << count << " output is: " << split <<" at: " << sc_delta_count() << std::endl;
        count++;
        
    }
    sc_stop();
}

void kpn :: Add()
{
    while(true)
    {
        b.write(a.read()+c.read());
        
    }
    
} 

void kpn :: Delay()
{   while(true)
    {
        c.write(d.read());
        
    }

    
}

