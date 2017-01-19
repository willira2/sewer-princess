/*********************************************************************
 ** Program Filename: main.cpp
 ** Author: Rachel Williams
 ** Date: 3 - 7- 16
 ** Description: main file for Final Project
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "sm.hpp"
#include "space.hpp"
#include "standard.hpp"
#include "ladder.hpp"
#include "Start.hpp"
#include "palace.hpp"
#include "mtms.hpp"
#include "riverbank.hpp"
#include "river.hpp"
#include "maintunnel.hpp"
#include "bedroom.hpp"
#include "ww.hpp"


#include <iostream>

int main()
{
    srand(time(NULL));
    
    SM princess; //create sewer monster princess 
    
    Ladder ladderRoom; //create ladder room
    Start startRoom; //create start room
    Palace palaceEntrance; //create palace entrance
    MTMS moletown; //create Mole Town Main Street
    RiverBank rb; //create the river bank
    River river; //create the river
    MT tunnel; //create main tunnel
    Bedroom bed; //create bedroom
    WW willys; //create Wino Willy's
    
    //set pointers
    ladderRoom.setPointers(&startRoom, NULL, &moletown, &palaceEntrance, &princess);
    startRoom.setPointers(&ladderRoom, &rb, &palaceEntrance, &moletown, &princess);
    palaceEntrance.setPointers(&startRoom, &rb, NULL, &tunnel, &princess);
    moletown.setPointers(&willys, &rb, &startRoom, NULL, &princess);
    rb.setPointers(&river, &palaceEntrance, &startRoom, &moletown, &princess);
    river.setPointers(&willys, &rb, &palaceEntrance, NULL, &princess);
    tunnel.setPointers(&bed, &palaceEntrance, NULL, NULL, &princess);
    bed.setPointers(&palaceEntrance, &tunnel, NULL, NULL, &princess);
    willys.setPointers(&moletown, &river, NULL, NULL, &princess);
    
    
    princess.setCurrentSpace(&startRoom);
    Space* currentRoom = princess.getCurrentSpace();
    
    std::cout << "\"Unbelievable, just unbelievable what he's done this time. Does Father not even care about what I want?\n";
    std::cout << "He claims he did this for me, but he's lying. He's done this for him\nand his precious treaty with the LizardPerson People.\n";
    std::cout << "I don't even know Prince Varanus!";
    std::cout << " Why would I agree to marry someone I don't even know?! \nOh, that's right. I didn't agree to it. Father did. ";
    std::cout << "Without even asking me. \nI'm a proud princess from an ancient line of sewer monsters, and I will not be ";
    std::cout << "treated like this!\"\n\n";
    
    std::cout << "It's then that you realize what you have to do: You have to leave. You have to get away! \nYou'll never be your own ";
    std::cout << "sewer monster so long as you live under Father's thumb. \nAnd now is the time to realize your dream to be with HIM,";
    std::cout << "\nthat mysterious human you've seen the past few weeks through the very same sidewalk grate that's above your head now.\n";
    std::cout << "You've always been told that humans are pathetic weaklings who can't understand the majesty of sewage, \nbut this man seems";
    std::cout << " different. You love him, and you must be with him. \nYou'll need to gather some romantic items, declare your love for him, \nand he'll";
    std::cout << "surely take you away!\n\n";
    
    std::cout << "But you'll have to move quickly. Prince Varanus and his entourage are on their way to finalize the betrothal.\n";
    std::cout << "You need to gather the following items: \n1 bottle of hooch from Wino Willy who lives off Main Street in Mole Town";
    std::cout << "\n6 dead rats to form a lovely bouquet for your beloved \n6 candle blobs from the river to set the ambience for your";
    std::cout << " first meeting (don't forget to light them!)\n\n";
    
    std::cout << "There's a ladder right behind you that will take you to the surface after you've gathered all of those items and\n";
    std::cout << "tidied up your makeup in your bedroom. Watch out for Father, though. He's probably lurking in the Great Hall\n";
    std::cout << "and will try to stop you on your way to your bedroom.\n";
    
    while (princess.getMoves() > 0 && currentRoom != NULL)
    {
        currentRoom = princess.getCurrentSpace();
        if(currentRoom != NULL)
        {
          currentRoom->menu();
        }
    }
    
    if(princess.getMoves() <= 0)
    {
        std::cout << "\nYou're out of time! Prince Varanus has arrived.\n";
        std::cout << "It turns out he's not such a bad LizardPerson, and you have a very happy life together.\n";
        std::cout << "\n\nFIN\n";
    }
    
    return 0;
}
