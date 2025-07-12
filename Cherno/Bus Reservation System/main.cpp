/*theres gonna be buses; - > and the user will pick which destination to go to;
and then the destination that user wants to go to those buses will appear to him
and he'll choose from it so;

Data layout :
buses : are going to be strings and will be held in some BusManager; - > which manages the bus management

steps :
take user input in form of a string; and validate it if it is the correct string; - > const char* : DONE
- Make a BusManager And Bus Class 
- Buses are just strings; so i suppose just make BusManager no need for Bus Class
- BusManager should do the following : 
{
- have Buses(strngs array);
- have a function that shows the user the Buses corresponding to the destination choice;
- thats about it so i suppose 
}

*/
#include <iostream>
#include <limits>
#include "Bus.h"

int main()
{

    bool gamerunning = true;
    char buffer[16];
    CharBuffer UserDestChoice{buffer,0,16};
    BusManager _BusManager;
    while(gamerunning)
    {
        Log("Enter Your Choice ");
        std::cin>>UserDestChoice;
        if(CheckUser_Char_Congruence(UserDestChoice,"exit")) 
        {
            gamerunning = false;
            break;
        } else {
            _BusManager.ShowBuses_Dest(UserDestChoice);
        }
    }

}


/*
Mistakes :
     if(DestinationToVisit == "Exit")  ok so this wont work becuse ur comparing char[32] to const char[5] " a literal "
    so u need  to properly check if the characters of first chars match them;
    std::istream& operator>>(std::istream& istreamRead,char* CharBufferWrite,int BufferSize)
     // so whne working with overloading stream operators u have to remember that because the work in binary objects 
     so theres only basically 2 it takes in a char(or any obj) and istream*/