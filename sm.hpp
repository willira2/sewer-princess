/*********************************************************************
 ** Program Filename: sm.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 7 - 16
 ** Description: header file for SM class
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef sm_hpp
#define sm_hpp

#include <cstdlib>

class Space;

class SM{
    
private:
    bool primpStatus;
    int bag [3];
    int strength;
    int moves;
    int maxMoves;
    
    Space* currentSpace;
    
public:
    SM()
    {
        strength = 10;
        primpStatus = false;
        moves = 50;
        
        for(int i = 0; i < 3; i++)
        {
            bag[i] = 10;
        }
        
        currentSpace = NULL;
    }
    
    bool getPrimpStatus();
    void setPrimpStatus(bool);

    bool checkBagStatus();
    void setBagContents(int, int);
    int getBagContents(int);
    int getNeededNumber(int);
    
    int getStrength() const;
    void setStrength(int);
    
    int getMoves() const;
    void setMoves();
    
    void setCurrentSpace(Space*);
    Space* getCurrentSpace();
    
};

#endif
