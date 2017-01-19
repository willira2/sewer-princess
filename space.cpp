/*********************************************************************
 ** Program Filename: space.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 8 - 16
 ** Description: implementation file for space class
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "space.hpp"
#include "sm.hpp"

#include <iostream>

/*********************************************************************
 ** Function: setCandlesLit
 ** Description: changes boolean value of candlesLit member. condition
 checking is done in SM class
 ** Parameters: bool
 ** Pre-Conditions: none
 ** Post-Conditions: candlesLit is updated
 *********************************************************************/
void Space::setCandlesLit(bool update)
{
    candlesLit = update;
}

/*********************************************************************
 ** Function: getCandlesLit
 ** Description: getter method, returns candlesLit
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: candlesLit returned
 *********************************************************************/
bool Space::getCandlesLit()
{
    return candlesLit;
}

/*********************************************************************
 ** Function: setPointers
 ** Description: sets "doorways" in each space to other spaces and sets
 each space's player pointer. used in main
 ** Parameters: four Space pointers, one SM pointer
 ** Pre-Conditions: none
 ** Post-Conditions: pointers for space object are assigned
 *********************************************************************/
void Space::setPointers(Space* s1, Space* s2, Space* s3, Space* s4, SM* prin)
{
    spIn.p1 = s1;
    spIn.p2 = s2;
    spIn.p3 = s3;
    spIn.p4 = s4;
    
    spIn.player = prin;
}

/*********************************************************************
 ** Function: getUserInput
 ** Description: validates user input and reprompts if input is out of
 bounds for menu choice. used in menu() functions.
 ** Parameters: three int's: the user's input, and the range for the 
 menu
 ** Pre-Conditions: none
 ** Post-Conditions: input is validated
 *********************************************************************/
int Space::getUserInput(int input, int start, int end)
{
    std::cin.ignore();
    
    while((input < start) | (input > end))
        {
            std::cout << "Sorry, not a valid choice. Choose again.\n";
            std::cin >> input;
            std::cin.ignore();
        }
    return input;
}

