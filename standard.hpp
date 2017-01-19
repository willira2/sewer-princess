/*********************************************************************
 ** Program Filename: standard.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for base class Standard. Standard is 
 derived from Space and parents Start, Palace, MTMS, and Riverbank
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef standard_hpp
#define standard_hpp

#include "space.hpp"

class Standard:public Space{

public:
    Standard()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
        spIn.player = NULL;
    }
    
    virtual void special();
    virtual void menu() = 0;
};

#endif
