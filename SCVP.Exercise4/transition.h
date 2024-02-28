#ifndef TRANSITION_H
#define TRANSITION_H

#include <systemc.h>

#include "place.h"
using namespace std;
// Transition:
// TODO
template<unsigned int N=1, unsigned int M=1, unsigned int L=0>
SC_MODULE(transition)
{
    public:

    sc_port<placeInterface, N, SC_ALL_BOUND> in;
    sc_port<placeInterface, M, SC_ALL_BOUND> out;
    sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

    SC_CTOR(transition)
    {}

    // void fire()
    // {   
    //     // for(int i=0; i<N; i++)
    //     // {

    //     //     if(in[i]->testTokens() != 0)
    //     //     {
    //     //         cout << this->name() << ": Fired" << endl;
    //     //         in[i]->removeTokens(1);
    //     //         out[i]->addTokens(1);
    //     //     }
    //     //     else
    //     //     {
    //     //         cout << this->name() << ": NOT Fired" << endl;
    //     //     }

    //     // }
    //     bool canFire = true;
    //     for (int i = 0; i < N; ++i) {
    //         if (in[i]->testTokens() == 0) {
    //             canFire = false;
    //             break;
    //         }
    //     }

    //     if (canFire) {
    //         std::cout << this->name() << ": Fired" << std::endl;
    //         for (int i = 0; i < N; ++i) {
    //             in[i]->removeTokens();
    //         }
    //         for (int i = 0; i < M; ++i) {
    //             out[i]->addTokens();
    //         }
    //     } else {
    //         std::cout << this->name() << ": NOT Fired" << std::endl;
    //     }
    // }
    void fire()
    {
        // Check for enough tokens in regular input places
        bool canFire = true;
        for (int i = 0; i < N; ++i) {
            if (in[i]->testTokens() == 0) {
                canFire = false;
                break;
            }
        }

        // Check for no tokens in inhibitor places
        for (int i = 0; i < L; ++i) {
            if (inhibitors[i]->testTokens() != 0) {
                canFire = false;
                break;
            }
        }

        if (canFire) {
            std::cout << this->name() << ": Fired" << std::endl;
            // Remove tokens from input places
            for (int i = 0; i < N; ++i) {
                in[i]->removeTokens();
            }
            // Add tokens to output places
            for (int i = 0; i < M; ++i) {
                out[i]->addTokens();
            }
        } else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
    }
};




#endif // TRANSITION_H










