/*********************************************************************
 ** Program Filename: start.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for start class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef Start_hpp
#define Start_hpp

#include "space.hpp"
#include "standard.hpp"

class Start: public Standard{
    
public:
    Start()
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
