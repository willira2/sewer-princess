/*********************************************************************
 ** Program Filename: space.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 7 -16
 ** Description: header file for parent class space
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef space_hpp
#define space_hpp

#include <cstdlib>
#include "sm.hpp"

class Space{
private:
    struct spaceInfo{
        Space* p1;
        Space* p2;
        Space* p3;
        Space* p4;
        SM* player;
    };
    
    bool candlesLit;
    
public:
    Space()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
        spIn.player = NULL;
        candlesLit = false;
    }
    
    ~Space()
    {
        spIn.p1 = NULL;
        spIn.p2 = NULL;
        spIn.p2 = NULL;
        spIn.p3 = NULL;
        spIn.p4 = NULL;
    }
    
    Space::spaceInfo spIn;
    
    virtual void menu() = 0;
    virtual void special() = 0;
    
    void setCandlesLit(bool);
    bool getCandlesLit();
    
    void setPointers(Space*, Space*, Space*, Space*, SM*);
    int getUserInput(int, int, int);
};

#endif
