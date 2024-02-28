#ifndef PLACE_H
#define PLACE_H

#include <systemc.h>

// Place Interface:
// TODO

class placeInterface : public sc_interface
{
    public:
        virtual void addTokens() = 0;
        virtual void removeTokens() = 0;
        virtual bool testTokens() = 0;

};


// Place Channel:
// TODO

template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface
{   private:
    unsigned int tokens; // current number of tokens in place

    public:
    place(unsigned int initialTokens) : tokens(initialTokens){}

    void addTokens()
    {
        tokens +=Win;

    }

    void removeTokens()
    {
        tokens -= Win;
    }

    bool testTokens()
    {
        return tokens >= Wout;
    }
};
#endif // PLACE_H
