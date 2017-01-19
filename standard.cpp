/*********************************************************************
 ** Program Filename: standard.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: implementation file for Standard class. contains function
 definition for special function that Standard derived classes share
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "standard.hpp"
#include "space.hpp"

#include <cstdlib>
#include <iostream>

/*********************************************************************
 ** Function: special() 
 ** Description: special function for standard spaces (Riverbank, 
 palace entrance, Mole Town Main Street, and the starting area). 40% 
 chance of finding 1 to 3 rats in any of those areas. If there is a rat
 (or rats), they are added to your bag.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there are rats in the area, they are added to 
 your bag
 *********************************************************************/
void Standard::special()
{
    int anyRats = 1 + (rand() % 100);
    int numberOfRats = 1+ (rand() % 3);
    
    if (anyRats <= 40)
    {
        std::cout << "You see " << numberOfRats << "!\n";
        std::cout << numberOfRats << " added to your bag.\n";
        
        spIn.player->setBagContents(0, numberOfRats);
    }
    
    else
    {
        std::cout << "Nope, no rats in here.\n";
    }
}


