/*********************************************************************
 ** Program Filename: start.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: implementation file for start class
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "space.hpp"
#include "Start.hpp"

#include <iostream>

/*********************************************************************
 ** Function: menu()
 ** Description: gives menu options for this space
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: moves Princess or calls action depending on user
 input
 *********************************************************************/
void Start::menu()
{
    int choice;
    int choice2;
    
    do {
        std::cout << "\nYou're in the starting area. What do you want to do?\n";
        std::cout << "1 - Go somewhere else\n";
        std::cout << "2 - Any rats around here?\n";
        std::cout << "3 - what's in my bag?\n";
        std::cout << "4 - what's my strength?\n";
        std::cout << "5 - what's left to do?\n";
        std::cout << "6 - how much time do I have?\n";
        
        std::cin >> choice;
        
        choice = getUserInput(choice, 1, 6);
        
        switch (choice) {
                
                //go somewhere else
            case 1:
                std::cout << "Where do you want to do?\n";
                std::cout << "1 - go to Mole Town Main Street\n";
                std::cout << "2 - turn around and walk over to the ladder\n";
                std::cout << "3 - go to the river\n";
                std::cout << "4 - go to the palace\n";
                
                std::cin >> choice2;
                
                choice2 = getUserInput(choice2, 1, 4);
                
                switch (choice2) {
                        //go to Mole Town Main Street
                    case 1:
                        spIn.player->setCurrentSpace(spIn.p4);
                        spIn.player->setMoves();
                         
                        break;
                        
                        //go to ladder
                    case 2:
                        spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
                         
                        break;
                        
                        //go to the river
                    case 3:
                        spIn.player->setCurrentSpace(spIn.p2);
                        spIn.player->setMoves();
                         
                        break;
                        
                        //go to the palace
                    case 4:
                        spIn.player->setCurrentSpace(spIn.p3);
                        spIn.player->setMoves();
                         
                        break;
                }
                
                break;
                
                //catch rats
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
    } while (choice != 1);
}
