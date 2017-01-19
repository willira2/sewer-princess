/*********************************************************************
 ** Program Filename: river.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for River class space
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef river_hpp
#define river_hpp

#include "space.hpp"

class River:public Space{
    
public:
    River()
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
