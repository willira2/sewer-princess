/*********************************************************************
 ** Program Filename: river.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 9 - 16
 ** Description: implementation file for river space
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "river.hpp"
#include <iostream>

/*********************************************************************
 ** Function: special function for the river.  
 ** Description:
 ** Parameters: dive for fat candles
 ** Pre-Conditions:
 ** Post-Conditions:
 *********************************************************************/
void River::special()
{
    //check health
    if(spIn.player->getStrength() < 5)
    {
        int strengthChoice;
        
        std::cout << "You don't have enough strength for that.\n";
        std::cout << "Your strength: " << spIn.player->getStrength();
        std::cout << "Needed strength: at least 5\n";
        
        std::cout << "Eat a rat and regain some strength? 1 rat = 2 strength\n";
        std::cout << "1 - yeah, I could use a snack.\n";
        std::cout << "2 - no, let's just go somewhere else.\n";
        
        std::cin >> strengthChoice;
        
        strengthChoice = getUserInput(strengthChoice, 1, 2);
        
        if((strengthChoice == 1) && (spIn.player->getBagContents(1) < 1))
           {
               std::cout << "Aww man, you don't have any rats in your bag.\n";
           }
       
        else if(strengthChoice == 1)
        {
            spIn.player->setBagContents(1, -1);
            spIn.player->setStrength(2);
            
            std::cout << "Mmmm, rat.\n";
            std::cout << "Alright, let's dive!\n";
            
            this->special();
        }
        
        else if (strengthChoice == 2)
        {
            this->menu();
        }
    }
    
    else
    {
        int anyCandles = 1 + (rand() % 100);
        int numberOfCandles = 1+ (rand() % 2);
        int choice;
        
        if (anyCandles <= 50)
        {
            std::cout << "You find " << numberOfCandles << "!\n";
            std::cout << numberOfCandles << " added to your bag.\n";
            
            spIn.player->setBagContents(2, numberOfCandles);
        }
        
        else
        {
            std::cout << "Nope, no blobs in here.\n";
        }
        
        int isRiverStrong = 1 + (rand() % 2);
        int riverForce = 1 + (rand() % 3);
        
        if(isRiverStrong == 1)
        {
            std::cout << "The current is pretty strong. You lose ";
            std::cout << riverForce << " strength\n";
            
            spIn.player->setStrength(-riverForce);
        }
        
        std::cout << "Dive deeper?\n";
        std::cout << "1 - yes\n";
        std::cout << "2 - no, let's go back to the surface\n";
        std::cin >> choice;
        
        choice = getUserInput(choice, 1, 2);
        
        int deeperCandles = 1 + (rand() % 100);
        int numberOfDeepCandles = 1+ (rand() % 2);
        
        if(choice == 1)
        {
            //decrease health
            spIn.player->setStrength(-1);
            std::cout << "Wow, this current is vicious down here. You lose a strength point...\n";

            if(deeperCandles <= 30)
            {
                std::cout << "You find " << numberOfDeepCandles << " blob(s)!\n";
                std::cout << numberOfDeepCandles << " added to your bag.\n";
                
                spIn.player->setBagContents(2, numberOfDeepCandles);
            }
            
            else
            {
                std::cout << "No blobs in sight....\n";
            }
            
            std::cout << "Keep diving?\n";
            std::cout << "1 - yes\n";
            std::cout << "2 - no\n";
            
            int deepDiveContinueChoice;
            std::cin >> deepDiveContinueChoice;
            
            deepDiveContinueChoice = getUserInput(deepDiveContinueChoice, 1, 2);
            
            if(deepDiveContinueChoice == 1)
            {
                if(deeperCandles <= 25)
                {
                    std::cout << "You find 1 blob!\n";
                    std::cout << "1 added to your bag.\n";
                    
                    spIn.player->setBagContents(2, numberOfDeepCandles);
                }
                
                else
                {
                    std::cout << "No blobs in sight....\n";
                }

                
                std::cout << "\nWhoa, what's that?\n";
                std::cout << "It kinda looks like some kind of tunnel leading off under the riverbank.\n";
                std::cout << "Check it out?\n";
                std::cout << "1 - yes\n";
                std::cout << "2 - no\n";
                
                int checkOutTunnel;
                std::cin >> checkOutTunnel;
                
                checkOutTunnel = getUserInput(checkOutTunnel, 1, 2);
               
                int secretBottle = 1 + (rand() % 100);
                if(checkOutTunnel == 1)
                {
                    if (secretBottle <= 40)
                    {
                        std::cout << "Ouch, what was that?! There's something hard stuck in the muck.\n";
                        std::cout << "You pull it out to reveal a full bottle of hooch. Looks like you\n";
                        std::cout << "found someone's secret stash! Time to get to the surface, though.\n";
                        std::cout << "You're almost out of air!\n";
                        
                        spIn.player->setBagContents(1, 1);
                    }
                    
                    std::cout << "Swimming, swimming...\n\n\n";
                    std::cout << "Finally! You see light up above.\n";
                    std::cout << "You break the surface in the fountain at the palace entrance.";
                    std::cout << " Weird. Who knew there was a shortcut there?\n";
                    
                    spIn.player->setCurrentSpace(spIn.p3);
                    spIn.player->setMoves();
                     
                }
                
                else
                {
                    this->menu();
                }
            }
            
            else
            {
                this->menu();
            }
        }
        
        else
        {
            this->menu();
        }
    }
}

/*********************************************************************
 ** Function: menu()
 ** Description: gives menu options for this space
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: moves Princess or calls action depending on user
 input
 *********************************************************************/
void River::menu()
{
    int choice;
    int choice2;
    
        std::cout << "\nYou're in the river. What do you want to do?\n";
        std::cout << "1 - Go somewhere else\n";
        std::cout << "2 - Dive for some candle blobs!\n";
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
                std::cout << "1 - swim up Wino Willy's secret shortcut and give him a heart attack\n";
                std::cout << "2 - go back to the river bank\n";
                
                std::cin >> choice2;
                
                choice2 = getUserInput(choice2, 1, 4);
                
                switch (choice2) {
                    //go to Wino Willy's
                    case 1:
                        spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
                         
                        
                        break;
                        
                    //go to bank
                    case 2:
                        spIn.player->setCurrentSpace(spIn.p2);
                        spIn.player->setMoves();
                         
                        break;
                }
        
                break;
                
            //dive for fat blobs
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

