#ifndef SUBNET_H
#define SUBNET_H

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
template<unsigned int N=1, unsigned int M=1>
SC_MODULE(subnet)
{
    public:
    
    sc_port<placeInterface, N, SC_ALL_BOUND> IN;
    sc_port<placeInterface, M, SC_ALL_BOUND> OUT;

    SC_CTOR(subnet) : ACT("ACT") , RD("RD"), PRE("PRE"), WR("WR"), ACTIVE(0), IN("IN") ,OUT("OUT")
    {
        ACT.in.bind(IN);
        ACT.out.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        
        PRE.in.bind(ACTIVE);
        PRE.out.bind(OUT);
        
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
        
        SC_THREAD(process);
    }
    public:
    transition<1,1> ACT;
    transition<1,1> RD;
    transition<1,1> PRE;
    transition<1,1> WR;

    place<3,3> ACTIVE;
    void process()
    {}

};
#endif // SUBNET_H
