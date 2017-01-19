/*********************************************************************
 ** Program Filename: bedroom.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: implementation file for Bedroom class
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "bedroom.hpp"
#include <iostream>

/*********************************************************************
 ** Function: special
 ** Description: princess primps for her meeting with her love. calls 
 setPrimpStatus() in SM class and changes SM object primpStatus to true. 
 special() can be called multiple times, but boolean only changes the
 first time it's called. this action must be done before princess can
 go up the ladder
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: SM object primpStatus is set to true
 *********************************************************************/
void Bedroom::special()
{
    spIn.player->setPrimpStatus(true);
    
    std::cout << "A little tasteful slime to highlight your cheekbones...\n";
    std::cout << "Sharpen your claws just a bit...\n";
    std::cout << "Beautiful!\n";
    
    int primpChoice;
    
    do {
        std::cout << "Primp some more?\n";
        std::cout << "1 - YASS\n";
        std::cout << "2 - No, I cannot be more beautiful and terrifying to behold than I am currently.\n";
        
        std::cin >> primpChoice;
        
        primpChoice = getUserInput(primpChoice, 1, 2);
        
        if(primpChoice == 1)
        {
            std::cout << "Adding more slime...\n";
        }
        
        else
        {
            this->menu();
        }
    } while (primpChoice != 2);
    
}


/*********************************************************************
 ** Function: menu()
 ** Description: gives menu options for this space
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: moves Princess or calls action depending on user
 input
 *********************************************************************/
void Bedroom::menu()
{
    int choice, choice2, landing;
    
    landing = 1 + (rand() % 3);
    
    std::cout << "\nYou're in your bedroom. What do you want to do?\n";
    std::cout << "1 - leave\n";
    std::cout << "2 - get pretty\n";
    std::cout << "3 - what's in my bag?\n";
    std::cout << "4 - what's my strength?\n";
    std::cout << "5 - what's left to do?\n";
    std::cout << "6 - how much time do I have?\n";
    
    std::cin >> choice;
    
    choice = getUserInput(choice, 1, 4);
    
    switch (choice) {
            
        //go somewhere else
        case 1:
            std::cout << "Where do you want to go?\n";
            std::cout << "1 - back through the Great Hall\n";
            std::cout << "2 - jump out my window and hope I land in the fountain at the palace entrance\n";
            
            std::cin >> choice2;
            
            choice2 = getUserInput(choice2, 1, 2);
            
            switch (choice2) {
                //go to main tunnel
                case 1:
                    spIn.player->setCurrentSpace(spIn.p2);
                    spIn.player->setMoves();
                     
                    break;
                    
                //jump out window
                case 2:
                    if(landing != 1)
                    {
                       spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
 
                    }
                    
                    else
                    {
                        std::cout << "Whoops, landing was a little off. -2 strength. \n";
                        spIn.player->setStrength(-2);
                        spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
                         
                    }
                    break;
            }
            break;
            
        //primp
        case 2:
            this->special();
            break;
            
        case 3:
            std::cout << "Bag inventory:\n";
            std::cout << spIn.player->getBagContents(0) << " rat(s)\n";
            std::cout << spIn.player->getBagContents(1) << " bottles(s) of hooch\n";
            std::cout << spIn.player->getBagContents(2) << " candle blob(s)\n";
            break;
            
        case 4:
            std::cout << "Your strength is currently at " << spIn.player->getStrength() << ".\n";
            break;
            
        case 5:
            std::cout << "You need " << spIn.player->getNeededNumber(0) << " rat(s), ";
            std::cout << spIn.player->getNeededNumber(1) << " bottle(s) of hooch, and ";
            std::cout << spIn.player->getNeededNumber(2) << " candle blob(s).\n";
            break;
            
        case 6:
            std::cout << "You have " << spIn.player->getMoves() << " moves left.\n";
            break;
            

    }
}


