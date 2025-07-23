#include <iostream>
// make a program that checks for Input if its a number or a string;
#include <cctype> // for std::isdigit(); returns true if 0-9;
#include <limits>
#include "StudentData.h"

int main()
{
    bool gamerunning = true;
    while(gamerunning)
    {
        while(std::cin>>std::ws) // keep asking for input and remove the whitespaces at the start if given;
        {
            StudentData _StudentData; // creates each input; like ... .. . . <- input1 this is created;
            while(_StudentData.Valid()) // check if studentData is valid;
            {   
            char NextChar = std::cin.peek();
            if(NextChar == EOF ||NextChar == '\n'){break;}  // <-- this means that u have reached the end of the input;
            if(std::isdigit(NextChar))
            { // its an int if (condition)
                _StudentData.IntInput();
            } else
            { // its a string of text like Text Text so we will either stop at EOF or a number

                std::string InputText;
                std::cin>>InputText;
                if(std::cin.peek() == ' ') // whitespace char then use manipulator;
                {
                    std::cin>>std::ws;
                }
                std::cout<<"You Entered The Text : "<<InputText<<std::endl;
            }
            }
            std::cout<<"would u like to quit? if so Press x and hit enter"<<std::endl;
            char lol;
            std::cin>>lol;
            if(lol == 'X' || lol == 'x')
            {
                gamerunning = false;
                break;
            }
        }
    }
}
