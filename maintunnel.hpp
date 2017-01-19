/*********************************************************************
 ** Program Filename: maintunnel.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for MT class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef maintunnel_hpp
#define maintunnel_hpp

#include "space.hpp"

class MT:public Space{
    
public:
    MT()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
        spIn.player = NULL;
    }
    
    virtual void special();
    virtual void menu();
};

#endif
