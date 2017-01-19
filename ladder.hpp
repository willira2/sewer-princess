/*********************************************************************
 ** Program Filename: ladder.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 8 - 16
 ** Description: implementation file for ladder class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef ladder_hpp
#define ladder_hpp

#include "space.hpp"

class Ladder:public Space{
    
public:
    Ladder()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
        spIn.player = NULL;
    };
    
    virtual void special();
    virtual void menu();
    
    void proclaimLove();
    
};

#endif
