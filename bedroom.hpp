/*********************************************************************
 ** Program Filename: bedroom.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for Bedroom class space
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef bedroom_hpp
#define bedroom_hpp

#include "space.hpp"

class Bedroom:public Space{
    
public:
    Bedroom()
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
