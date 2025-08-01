// create a program takes in text and Html element type and outputs that;
// just create Inputfirst;
#include <fstream>
#include <iostream>
#include "./Template C++/Log.h"

int main()
{
    std::ofstream Ofile;
    Ofile.open("index.html",std::ios::app);
    std::string TextInput;
    Log::LogMessage("Input String of Text");
    std::getline(std::cin,TextInput);
    Ofile<<"<h1>"<<TextInput<<"</h1>"<<"\n";
} // OOO SO I COULD CREATE SOME KIND OF FRONTEND INTERFACE Library to add code to 
// html css and js;