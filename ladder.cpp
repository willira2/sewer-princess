/*********************************************************************
 ** Program Filename: ladder.hpp
 ** Author: Rachel Williams
 ** Date: 3 - 8 - 16
 ** Description: implementation file for ladder class
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "ladder.hpp"
#include "space.hpp"
#include <iostream>

/*********************************************************************
 ** Function: special
 ** Description: special function for ladder class lights the candles
 before allowing the SM to ascend to the surface. There must be at least
 6 rats, a bottle of hooch, and 6 candles in the bag for the candles to 
 light. condition checking is done in SM class.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if conditions are met, candles are lit
 *********************************************************************/
 void Ladder::special()
{
    if(spIn.player->checkBagStatus())
    {
        setCandlesLit(true);
        std::cout << "Candles are now lit.\n";
    }
    
    else
    {
        std::cout << "You can't light the candles yet! You don't have all your items.\n";
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
void Ladder::menu()
{
    int choice;
    int choice2;
    
    do {
        std::cout << "You're standing in front of the ladder. What do you want to do?\n";
        std::cout << "1 - go somewhere else\n";
        std::cout << "2 - light the candles\n";
        std::cout << "3 - I'm ready! Go up the ladder!\n";
        std::cout << "4 - what's in my bag?\n";
        std::cout << "5 - what's my strength?\n";
        std::cout << "6 - what's left to do?\n";
        std::cout << "7 - how much time do I have?\n";
    
        std::cin >> choice;
        
        choice = getUserInput(choice, 1, 7);
        
        switch (choice) {
           
            //go somewhere else
            case 1:
                std::cout << "Where do you want to do?\n";
                std::cout << "1 - go to start\n";
                std::cout << "2 - go to Mole Town Main Street\n";
                std::cout << "3 - go to the Palace\n";
                
                std::cin >> choice2;
                
                choice2 = getUserInput(choice2, 1, 3);
                
                switch (choice2) {
                    //go to start
                    case 1:
                        spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
                        
                        break;
                    
                    //go to Mole Town Main Street
                    case 2:
                        spIn.player->setCurrentSpace(spIn.p3);
                        spIn.player->setMoves();
                        
                        break;
                    
                    //go to the Palace
                    case 3:
                        spIn.player->setCurrentSpace(spIn.p4);
                        spIn.player->setMoves();
                        
                        break;
                }
                
                break;
            
            //light the candles
            case 2:
                this->special();
                break;
                
            //go up the ladder
            case 3:
                //check conditions
                if(spIn.player->checkBagStatus() && getCandlesLit() && spIn.player->getPrimpStatus())
                {
                    this->proclaimLove();
                }
                
                else
                {
                    std::cout << "You're not ready yet!\n";
		    std::cout << "Are the candles lit?\n";
		    std::cout << "Have you primped?\n";
		    std::cout << "Do you have all your items?\n";
                    menu();
                }
                break;
                
            case 4:
                std::cout << "Bag inventory:\n";
                std::cout << spIn.player->getBagContents(0) << " rat(s)\n";
                std::cout << spIn.player->getBagContents(1) << " bottles(s) of hooch\n";
                std::cout << spIn.player->getBagContents(2) << " candle blob(s)\n";
                break;
                
            case 5:
                std::cout << "Your strength is currently at " << spIn.player->getStrength() << ".\n";
                break;
                
            case 6:
                std::cout << "You need " << spIn.player->getNeededNumber(0) << " rat(s), ";
                std::cout << spIn.player->getNeededNumber(1) << " bottle(s) of hooch, and ";
                std::cout << spIn.player->getNeededNumber(2) << " candle blob(s).\n";
                break;
                
            case 7:
                std::cout << "You have " << spIn.player->getMoves() << " moves left.\n";
                break;


        }
        
         } while ((choice != 1) && (choice != 3));
    
}

/*********************************************************************
 ** Function: proclaimLove
 ** Description: final function call of game, proclaims love to object
 of affection
 ** Parameters: none
 ** Pre-Conditions: bag contains at least 6 rats, 1 bottle of hooch, 
 6 candle blobs, and SM is primped
 ** Post-Conditions: I won't ruin the story.
 *********************************************************************/
void Ladder::proclaimLove()
{
    int input1, input2;
    
    std::cout << "*You rise from the depths of the sewer to face your love, the flame of the candles casting haunting shadows across your minatory countenance.";
    std::cout << " You are terrifying to behold, yet beguiling all the same. You are sensual, yet strong.\n";
    std::cout << "You extend your hands to your love, eager for him to take you from your wretched life, eager to be with him forever.*\n\n";
    
    std::cout << "\"AHHH!!! What is that THING?! It's hideous!\" he screeches.\n\n";
    
    std::cout << "What is he talking about?\n";
    std::cout << "1 - Look around for whatever hideous thing he said he's seen.\n";
    std::cout << "2 - Ignore him. It's probably just a nervous reaction to strong feelings of adoration. It happens.\n";
    
    std::cin >> input1;
    
    input1 = getUserInput(input1, 1, 2);
    
    if(input1 == 1)
    {
        std::cout << "Hmmm... I don't see anything...\n\n";
    }
    
    std::cout << "\"My love, from the moment I saw you, I knew we were meant to be together. I have left my home and my people to be with you.";
    std::cout << " To honor this moment, this moment where we begin our lives together, I have brought a romantic meal.\n";
    std::cout << "*You take the dead rats out of your bag.*\n\n";
    
    std::cout << "\"Help! Someone help! Call the police! This...this disgusting THING is throwing dead rats at me!\"\n\n";
    
    std::cout << "...Surely he's not talking about me?\n";
    std::cout << "*You take a step towards him.*\n\n";
    
    std::cout << "\"Don't come any closer! Yuck, is that slime?!\"\n\n";
    
    std::cout << "Your heart is breaking. Doesn't he understand that you're meant to be together?";
    std::cout << " Why doesn't he feel the same way?\n\n";
    
    std::cout << "\"Just get away from me!\"\n\n";
    
    std::cout << "1 - retreat back to the sewers and hope that your father can forgive you. You were wrong to think a ";
    std::cout << "human could ever love and appreciate you.";
    std::cout << " Maybe Prince Varanus isn't that bad. He seems like he might be scaly in all the right ways.\n";
    std::cout << "2 - eat this pathetic human.\n";
    
    std::cin >> input2;
    
    input2 = getUserInput(input2, 1, 2);
    
    while (input2 != 2)
    {
        int output = 1 + (rand() % 4);
        
        switch (output) {
            case 1:
                std::cout << "Are you sure? He called you disgusting!\n";
                std::cout << "(Choose 1 for yes or 2 for no)\n";
                std::cin >> input2;
                
                input2 = getUserInput(input2, 1, 2);
                
                break;
                
            case 2:
                std::cout << "You really want to slink back down into the sewer?";
                std::cout << " You know your father will never let this go if he finds out.\n";
                std::cout << "(Choose 1 for yes or 2 for no)\n";
                std::cin >> input2;
                
                input2 = getUserInput(input2, 1, 2);

                break;
                
            case 3:
                std::cout << "Oh come on, really? You're going to let him get away with this?\n";
                std::cout << "(Choose 1 for yes or 2 for no)\n";
                std::cin >> input2;
                
                input2 = getUserInput(input2, 1, 2);

                break;
                
            case 4:
                std::cout << "So you're just giving up?\n";
                std::cout << "(Choose 1 for yes or 2 for no)\n";
                std::cin >> input2;
                
                input2 = getUserInput(input2, 1, 2);

                break;
        }
    }
    
    std::cout << "\nYou eat him.\n\n";
    
    std::cout << "FIN\n";
    
    spIn.player->setCurrentSpace(NULL);
}
