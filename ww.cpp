/*********************************************************************
 ** Program Filename: ww.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 10 - 16
 ** Description: implementation file for WW class
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "ww.hpp"
#include <iostream>

/*********************************************************************
 ** Function: special
 ** Description: special function for WW class. haggle with Wino Willy 
 for a bottle of hooch. Willy names a price in the range of 10 to 13 rats.
 User enters a counter offer. Willy and User trade offers back and forth
 until Willy agrees on price. Willy's price is firm below a certain 
 point. User cannot offer more rats than are in bag. if you accept his 
 first offer, he'll let you use his shortcut to the river.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: get bottle of hooch added to bag
 *********************************************************************/
void WW::special()
{
    int shortcut, haggle1, haggle2, counter, price = 10 + (rand() % 3);
    int lowestPrice = price / 2;
    int midPrice = price * .75;
    
    std::cout << "\"I hear you need some hooch. Got a nice vintage back here, a whole two weeks.\"\n";
    std::cout << "\"Going price is " << price << ".\"\n";
    
    std::cout << "Accept this price?\n";
    std::cout << "1 - yes\n";
    std::cout << "2 - no\n";
    std::cin >> haggle1;
    
    haggle1 = getUserInput(haggle1, 1, 2);
    
        //if user accepts price and has enough rats to pay
        if(haggle1 == 1 && (spIn.player->getBagContents(0) >= price))
        {
            std::cout << "It's a deal! Good luck.\n";
            std::cout << "[Bottle of hooch added to bag.]\n";
            
            spIn.player->setBagContents(1, 1);
            spIn.player->setBagContents(0, -price);
            
            std::cout << "You know, I've got a little backdoor to the river here if you're looking for a shortcut.\n";
            std::cout << "1 - Yeah, I'll take that!\n";
            std::cout << "2 - No, thanks!\n";
            
            std::cin >> shortcut;
            
            shortcut = getUserInput(shortcut, 1, 2);
            
            std::cout << "shortcut = " << shortcut;
            
            //if user takes the shortcut
            if(shortcut == 1)
            {
                spIn.player->setCurrentSpace(spIn.p2);
                 
            }
        }
    
        //else if user accepts price but doesn't have enough rats
        else if (haggle1 == 1 && (spIn.player->getBagContents(0) < price))
        {
            std::cout << "You can't afford that price. You'll have to counter it.\n";
        }
    
        //else enter a counter when user selects 2 or doesn't have enough rats for first price
        else
        {
            std::cout << "Kinda high, Willy...\n";
            std::cout << "(Enter counter offer)\n";
            std::cin >> counter;
            std::cin.ignore();
            
                //verify that counter offer is valid
                while ((counter < 0) | (spIn.player->getBagContents(0) < counter))
                {
                    if (counter < 0)
                    {
                        std::cout << "You must enter a positive counter offer. Try again.\n";
                        std::cin >> counter;
                    }
                    
                    else
                    {
                        std::cout << "You don't have enough rats to pay that price!\n";
                        std::cout << "You have " << spIn.player->getBagContents(0) << " rats.\n";
                        std::cout << "Enter a different amount:\n";
                        std::cin >> counter;
                    }
                }
            
            //if user has enough for counter and counter is at least as great as midPrice
            if((spIn.player->getBagContents(0) >= counter) && (counter >= midPrice))
            {
                std::cout << "It's a deal! Good luck.\n";
                std::cout << "[Bottle of hooch added to bag.]\n";
                
                spIn.player->setBagContents(1, 1);
                spIn.player->setBagContents(0, -counter);
                
                std::cout << "You know, I've got a little backdoor to the river here if you're looking for a shortcut.\n";
                std::cout << "1 - Yeah, I'll take that!\n";
                std::cout << "2 - No, thanks!\n";
                    
                std::cin >> shortcut;
                
                shortcut = getUserInput(shortcut, 1, 2);
                
                if(shortcut == 1)
                {
                    spIn.player->setCurrentSpace(spIn.p2);                }
                    
            }
            
            else if(counter < lowestPrice)
            {
                //find Willy's new price which is his original price minus one fourth the difference of his
                //price and the user's counter
                int newPrice = price - ((price - counter) / 4);
                
                std::cout << "*staggers back* You'll give me " << counter << "?! Are you trying to rob me blind?\n";
                std::cout << "I'll take " << newPrice << ".\n";
                
                std::cout << "Accept this price?\n";
                std::cout << "1 - yes\n";
                std::cout << "2 - no\n";
                std::cin >> haggle2;
                
                haggle2 = getUserInput(haggle2, 1, 2);
                
                    //if user accepts price and has enough rats to pay
                    if(haggle2 == 1 && (spIn.player->getBagContents(0) >= newPrice))
                    {
                        std::cout << "It's a deal! Good luck.\n";
                        std::cout << "[Bottle of hooch added to bag.]\n";
                        
                        spIn.player->setBagContents(1, 1);
                        spIn.player->setBagContents(0, -newPrice);
                        
                        std::cout << "You know, I've got a little backdoor to the river here if you're looking for a shortcut.";
                        std::cout << "1 - Yeah, I'll take that!\n";
                        std::cout << "2 - No, thanks!\n";
                        
                        std::cin >> shortcut;
                        
                        shortcut = getUserInput(shortcut, 1, 2);
                        
                        //if user takes the shortcut
                        if(shortcut == 1)
                        {
                            spIn.player->setCurrentSpace(spIn.p2);
                             
                        }
                    }
                    
                    //else if user accepts price but doesn't have enough rats
                    else if (haggle2 == 1 && (spIn.player->getBagContents(0) < newPrice))
                    {
                        std::cout << "You can't afford that price. You'll have to counter it.\n";
                    }
                
                    //else enter a counter when user selects 2 or doesn't have enough rats for first price
                    else
                    {
                        std::cout << "Come on, Willy, cut me some slack, will you?\n";
                        std::cout << "(Enter counter offer)\n";
                        std::cin >> counter;
                        
                        while ((counter < 0) | (spIn.player->getBagContents(0) < counter))
                        {
                            if (counter < 0)
                            {
                                std::cout << "You must enter a positive counter offer. Try again.\n";
                                std::cin >> counter;
                            }
                            
                            else
                            {
                                std::cout << "You don't have enough rats to pay that price!\n";
                                std::cout << "You have " << spIn.player->getBagContents(0) << " rats.\n";
                                std::cout << "Enter a different counter:\n";
                                std::cin >> counter;
                            }
                        }
                        
                        //if user has enough for counter and counter is at least as great as lowestPrice
                        if((spIn.player->getBagContents(0) >= counter) && (counter >= lowestPrice))
                        {
                            std::cout << "It's a deal! Good luck.\n";
                            std::cout << "[Bottle of hooch added to bag.]\n";
                            
                            spIn.player->setBagContents(1, 1);
                            spIn.player->setBagContents(0, -counter);
                            
                        }
                        
                        //else user has enough for counter but it's lower than lowestPrice
                        else
                        {
                            int lastPrice = newPrice - ((newPrice - counter) / 4);
                            
                            std::cout << "Listen here, you're a nice sewer monster, so far as sewer monsters go, but I gotta make a living!\n";
                            std::cout << "I'll take " << lastPrice << " and that's final.\n";
                            
                            std::cout << "1 - Accept Wino Willy's final offer.\n";
                            std::cout << "2 - That price is absurd! I'm leaving.\n";
                            std::cin >> counter;
                            
                            counter = getUserInput(counter, 1, 2);
                            
                            if((counter == 1) && (spIn.player->getBagContents(0) >= lastPrice))
                            {
                                std::cout << "It's a deal! Good luck.\n";
                                std::cout << "[Bottle of hooch added to bag.]\n";
                                
                                spIn.player->setBagContents(1, 1);
                                spIn.player->setBagContents(0, -lastPrice);
                            }
                            
                            else if((counter == 1) && (spIn.player->getBagContents(0) < lastPrice))
                            {
                                std::cout << "\"What do you mean you can only give me " << spIn.player->getBagContents(0);
                                std::cout << "rats?? Get out of here, you cheat!\"\n";
                                std::cout << "*Wino Willy kicks you out of his house.*\n";
                            }
                        }
                    }
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
void WW::menu()
{
    int choice;
    
    do {
        std::cout << "\nYou're in Wino Willy's. What do you want to do?\n";
        std::cout << "1 - go back to Mole Town Main Street\n";
        std::cout << "2 - let's buy some hooch!\n";
        std::cout << "3 - what's in my bag?\n";
        std::cout << "4 - what's my strength?\n";
        std::cout << "5 - what's left to do?\n";
        std::cout << "6 - how much time do I have?\n";
        
        std::cin >> choice;
        
        choice = getUserInput(choice, 1, 6);
        
        switch (choice) {
            //go to the start area
            case 1:
                spIn.player->setCurrentSpace(spIn.p1);
                spIn.player->setMoves();
                break;
                
            //buy hooch
            case 2:
                if(spIn.player->getBagContents(0) > 0)
                {
                    this->special();
                }
                
                else
                {
                    std::cout << "You don't have any rats! You'll need some if you want to buy hooch from Wino Willy.\n";
                }
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
