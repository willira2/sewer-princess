/*********************************************************************
 ** Program Filename: mtms.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: header file for MTMS class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef mtms_hpp
#define mtms_hpp

#include "space.hpp"
#include "standard.hpp"


class MTMS: public Standard{
    
public:
    MTMS()
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
