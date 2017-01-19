/*********************************************************************
 ** Program Filename: riverbank.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for RiverBank class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef riverbank_hpp
#define riverbank_hpp

#include "space.hpp"
#include "standard.hpp"

class RiverBank: public Standard{
    
public:
    RiverBank()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
        spIn.player = NULL;
    }
    
    virtual void menu();
};

#endif
