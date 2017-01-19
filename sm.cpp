/*********************************************************************
 ** Program Filename: sm.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 7 - 16
 ** Description: SM class implementation file, contains method
 definitions
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "sm.hpp"
#include <iostream>

/*********************************************************************
 ** Function: getPrimpStatus
 ** Description: returns state of primpStatus. if SM has primped, it is 
 true. if SM has not primped or if she has and then jumped in the river, 
 it is false
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: primpStatus is returned
 *********************************************************************/
bool SM::getPrimpStatus()
{
    return primpStatus;
}

/*********************************************************************
 ** Function: setPrimpStatus
 ** Description: changes primpStatus to value of argument. This function
 is called in the bedroom, the river, and the fountain
 ** Parameters: bool
 ** Pre-Conditions: none
 ** Post-Conditions: primpChange is updated
 *********************************************************************/
void SM::setPrimpStatus(bool primpChange)
{
    primpStatus = primpChange;
}

/*********************************************************************
 ** Function: checkBagStatus
 ** Description: returns true if bag contains at least 6 dead rats, 
 a bottle of hooch, and six candles. returns false if not
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: true/false returned
 *********************************************************************/
bool SM::checkBagStatus()
{
    if(bag[0] >= 6 && bag[1] >= 1 && bag[2] >= 6)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

/*********************************************************************
 ** Function: setBagContents
 ** Description: updates bag array contents depending on the arguments.
first argument corresponds to element in array to be updated
 1st place is rats, 2nd place is candles, and 3rd place is hooch. second
 argument updates the value of that element.
 ** Parameters: int and int
 ** Pre-Conditions: arguments are valid
 ** Post-Conditions: array is updated
 *********************************************************************/
void SM::setBagContents(int location, int update)
{
    if((location <= 2) && (location >= 0))
    {
        bag[location] += update;
    }
    
    else
    {
        std::cout << "something went wrong with bag update\n";
    }
}

/*********************************************************************
 ** Function: getBagContents
 ** Description: returns value at specified bag array element
 ** Parameters: int for array location
 ** Pre-Conditions: none
 ** Post-Conditions: value at specified lcoation is returned
 *********************************************************************/
int SM::getBagContents(int location)
{
    int returnValue = bag[location];
    return returnValue;
}

/*********************************************************************
 ** Function: getNeededNumber
 ** Description: returns the necessary number of items that the player
 needs before being able to ascend the ladder. checks one location at
 a time
 ** Parameters: int for array location
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/
int SM::getNeededNumber(int location)
{
    int returnValue = 0;
    
    switch (location) {
        case 0:
            if(bag[0] < 6)
            {
                returnValue = 6 - bag[0];
            }
            
            else
            {
                returnValue = 0;
            }
            break;
            
        case 1:
            if(bag[1] < 1)
            {
                returnValue = 1;
            }
            
            else
            {
                returnValue = 0;
            }
            break;
            
        case 2:
            if(bag[2] < 6)
            {
                returnValue = 6 - bag[2];
            }
            
            else
            {
                returnValue = 0;
            }
            break;

    }
    return returnValue;
}


/*********************************************************************
 ** Function: getStrength
 ** Description: returns strength member. called when SM dives in river
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: strength is returned
 *********************************************************************/
int SM::getStrength() const
{
    return strength;
}

/*********************************************************************
 ** Function: setStrength
 ** Description: updates strength function by amount of argument. 
 strength is decremented through too much diving or incremented if SM
 eats a rat
 ** Parameters: int
 ** Pre-Conditions: none
 ** Post-Conditions: strength is updated
 *********************************************************************/
void SM::setStrength(int update)
{
    strength += update;
}

/*********************************************************************
 ** Function: getMoves
 ** Description: returns moves member. 
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: moves is returned
 *********************************************************************/
int SM::getMoves() const
{
    return moves;
}

/*********************************************************************
 ** Function: setMoves
 ** Description: decrements moves by 1
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: moves is updated
 *********************************************************************/
void SM::setMoves()
{
    moves--;
}

/*********************************************************************
 ** Function: setCurrentSpace
 ** Description: setter method for currentSpace
 ** Parameters: Space pointer
 ** Pre-Conditions: argument is valid
 ** Post-Conditions: currentSpace set to value of argument
 *********************************************************************/
void SM::setCurrentSpace(Space * nextCurrent)
{
    currentSpace = nextCurrent;
}

/*********************************************************************
 ** Function: getCurrentSpace
 ** Description: getter method for currentSpace
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: currentSpace returned
 *********************************************************************/
Space* SM::getCurrentSpace()
{
    return currentSpace;
}
