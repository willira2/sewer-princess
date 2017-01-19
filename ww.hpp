/*********************************************************************
 ** Program Filename: ww.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for WW class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef ww_hpp
#define ww_hpp

#include "space.hpp"

class WW:public Space{
    
public:
    WW()
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
