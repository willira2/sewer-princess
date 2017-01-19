/*********************************************************************
 ** Program Filename: maintunnel..cpp
 ** Author: Rachel Williams
 ** Date: 3 - 9 - 16
 ** Description: implementation file for maintunnel space
 ** Input: none
 ** Output: none
 *********************************************************************/

#include <iostream>
#include "maintunnel.hpp"

/*********************************************************************
 ** Function: special()
 ** Description: argues with King/Pops, certain answers leads to the king 
 emptying your bag. Princess goes to bedroom after completion of conversation, 
 no matter the outcome
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: depends on user's choices. Princess ends up in bedroom,
 but her bag might be empty
 *********************************************************************/
void MT::special()
{
    int firstReply, secondReply, thirdReply, fourthReply;
    
    std::cout << "\n\"Oh, look who decided to turn up!\"\n\n";
    std::cout << "Drats, it's Father.\n\n";
    std::cout << "\"Since you've decided to show your face here, I take that to mean ";
    std::cout << "that you have accepted the LizardPerson Prince's proposal and done right ";
    std::cout << "by your people.\"\n";
    
    std::cout << "1 - Yes, Father. I have conceded to your wisdom and will marry Prince Varanus.";
    std::cout << " I just need to go to my room to uh...get something...\n";
    std::cout << "2 - Whatever, Dad! You don't own me!\n";
    std::cout << "(Choose your reply)\n";
    
    std::cin >> firstReply;
    
    firstReply = getUserInput(firstReply, 1, 2);
    
    switch (firstReply) {
        case 1:
            std::cout << "\"Good. I'm glad to hear you're not being difficult like your mother. What's in the bag?\"\n";
            
            std::cout << "1 - Just some shopping.\n";
            std::cout << "2 - Wow, nosy much?\n";
            std::cout << "(Choose your reply)\n";
            
            std::cin >> secondReply;
            
            secondReply = getUserInput(secondReply, 1, 2);
            
            switch (secondReply) {
                case 1:
                    std::cout << "\"Shopping? Again? I'll be happy when it's Varanus footing the bill for that and not me. ";
                    std::cout << "Well, go on to your room, and do something with your hair. It's not dank at all.\"\n";
                    
                    spIn.player->setCurrentSpace(spIn.p1);
                    spIn.player->setMoves();
                     
                    break;
                    
                case 2:
                    std::cout << "\"You need to watch the attitude! Let me see that bag.\"\n";
                    std::cout << "*he rifles through the bag*\n";
                    
                    if((spIn.player->getBagContents(0) > 0) | (spIn.player->getBagContents(1) > 0) |
                       (spIn.player->getBagContents(2) > 0))
                    {
                        std::cout << "\"What is all this stuff for?\"\n";
                        
                        std::cout << "1 - Some things for Mother. She's hosting a Sips and Slimes party.\n";
                        std::cout << "2 - Uh, none of your business?\n";
                        std::cout << "(Choose your reply)\n";
                        
                        std::cin >> thirdReply;
                        
                        thirdReply = getUserInput(thirdReply, 1, 2);
                        
                        switch (thirdReply) {
                            case 1:
                                std::cout << "\"Females and their parties. Waste of time. Well, go on to your room.\"\n";
                                spIn.player->setCurrentSpace(spIn.p1);
                                spIn.player->setMoves();
                                 
                                break;
                                
                            case 2:
                                std::cout << "\"That's it. Attitude stops here and now.\"\n";
                                std::cout << "*he empties your bag*\n";
                                std::cout << "I'll be holding onto these things. Now go on to your room";
                                std::cout << " and put on some of that green slime for Prince Varanus\"\n";
                                
                                for(int i = 0; i < 3; i++)
                                {
                                    spIn.player->setBagContents(i, -spIn.player->getBagContents(i));
                                }
                                
                                spIn.player->setCurrentSpace(spIn.p1);
                                spIn.player->setMoves();
                                 
                                break;
                        }
                    }
                    
                    else
                    {
                        std::cout << "\"Huh, it's empty. Well, go on to your room.\"\n";
                        
                        spIn.player->setCurrentSpace(spIn.p1);
                        spIn.player->setMoves();
                         
                    }
                    break;
            }
            break;
            
        case 2:

            std::cout << "\"How dare you speak to your father that way! After all I've done for you!";
            std::cout << " Have I told you that Varanus has already shed his skin for your wedding dress?!\n";
            
            std::cout << "1 - Sorry, Father. I guess I'm just overexcited.\n";
            std::cout << "2 - Gross, Dad! I don't want anything to do with Varanus! He doesn't even smell bad!\n";
            std::cout << "(Choose your reply)\n";
            
            std::cin >> secondReply;
            
            secondReply = getUserInput(secondReply, 1, 2);
            
            switch (secondReply) {
                 case 1:
                    std::cout << "\"Apology accepted...this time. What's in the bag?\"\n";
                    
                    std::cout << "1 - Just some shopping.\n";
                    std::cout << "2 - Wow, nosy much?\n";
                    std::cout << "(Choose your reply)\n";
                    
                    std::cin >> thirdReply;
                    
                    thirdReply = getUserInput(thirdReply, 1, 2);
                    
                    switch (thirdReply) {
                        case 1:
                            std::cout << "\"Shopping? Again? I'll be happy when it's Varanus footing the bill for that and not me.";
                            std::cout << "Well, go on to your room, and do something with your hair. It's not dank at all.\"\n";
                            
                            spIn.player->setCurrentSpace(spIn.p1);
                            spIn.player->setMoves();
                             
                            break;
                            
                        case 2:
                            std::cout << "\"You need to watch the attitude! Let me see that bag.\"\n";
                            std::cout << "*he rifles through the bag*\n";
                            
                            if((spIn.player->getBagContents(0) > 0) | (spIn.player->getBagContents(1) > 0) |
                               (spIn.player->getBagContents(2) > 0))
                            {
                                std::cout << "\"What is all this stuff for?\"\n";
                                
                                std::cout << "1 - Some things for Mother. She's hosting a Sips and Slimes party.\n";
                                std::cout << "2 - Uh, none of your business?\n";
                                std::cout << "(Choose your reply)\n";
                                
                                std::cin >> fourthReply;
                                
                                fourthReply = getUserInput(fourthReply, 1, 2);
                                
                                switch (fourthReply) {
                                    case 1:
                                        std::cout << "\"Females and their parties. Waste of time. Well, go on to your room.\"\n";
                                        spIn.player->setCurrentSpace(spIn.p1);
                                        spIn.player->setMoves();
                                         
                                        break;
                                        
                                    case 2:
                                        std::cout << "\"That's it. Attitude stops here and now.\"\n";
                                        std::cout << "*he empties your bag*\n";
                                        std::cout << "I'll be holding onto these things. Now go on to your room";
                                        std::cout << " and stay there until Prince Varanus arrives.\"\n";
                                        
                                        for(int i = 0; i < 3; i++)
                                        {
                                            spIn.player->setBagContents(i, -spIn.player->getBagContents(i));
                                        }
                                        
                                        spIn.player->setCurrentSpace(spIn.p1);
                                         
                                        spIn.player->setMoves();
                                        
                                        break;
                                }
                            }
                            
                            else
                            {
                                std::cout << "\"Huh, it's empty. Well, go on to your room.\"\n";
                                
                                spIn.player->setCurrentSpace(spIn.p1);
                                spIn.player->setMoves();
                                 
                               
                            }
                            break;
                    }

                    
                case 2:
                    std::cout << "\"That's it. Attitude stops here and now.\"\n";
                    std::cout << "*he empties your bag*\n";
                    std::cout << "I'll be holding onto these things. Now go on to your room";
                    std::cout << " and put on some of that green slime I found below the high";
                    std::cout << " school.\n";
                    
                    for(int i = 0; i < 3; i++)
                    {
                        spIn.player->setBagContents(i, -spIn.player->getBagContents(i));
                    }
                    
                    spIn.player->setCurrentSpace(spIn.p1);
                    spIn.player->setMoves();
                     
                   
                    break;

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
void MT::menu()
{

    int choice;

    std::cout << "\nYou're in the Great Hall. What do you want to do?\n";
    std::cout << "1 - This is a bad idea. Go back to the palace entrance.\n";
    std::cout << "2 - Let's just try to get to my bedroom.\n";
    std::cout << "3 - what's in my bag?\n";
    std::cout << "4 - what's my strength?\n";
    std::cout << "5 - what's left to do?\n";
    std::cout << "6 - how much time do I have?\n";
    
    std::cin >> choice;
    
    choice = getUserInput(choice, 1, 6);
    
    switch (choice) {
        //go to the start area
        case 1:
            spIn.player->setCurrentSpace(spIn.p2);
            spIn.player->setMoves();
             
            break;
            
        //go to bedroom
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
