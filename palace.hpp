/*********************************************************************
 ** Program Filename: palace.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for Palace class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef palace_hpp
#define palace_hpp

#include "space.hpp"
#include "standard.hpp"


class Palace: public Standard{
    
public:
    Palace()
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
