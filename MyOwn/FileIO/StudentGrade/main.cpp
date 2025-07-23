/*Student Grade Management System:
 Read student names and grades from a file, calculate averages, 
 and write results to another file.*/

// ok so 1 file with a bunch of items ; if file not exist we create it same directory;
// so i suppoes fstream; would be used here;
// so just opening a file <fstream> and writing some data to it;
#include <iostream>
#include <fstream>
#include <limits>
#define NAME_MAX 100

struct Test
{
    char* Message;
    int UserInt;
    int MultiBy2;
    bool Valid = false;
};

std::istream& operator>>(std::istream& InStream,Test& InTest);
std::ostream& operator<<(std::ostream& OStream,Test& InTest);

int main()
{
    std::ofstream OFILE;
    OFILE.open("File.txt",std::ios::app); // by default if u dont specify trhe 2nd param then its set to ios::trunc;
    // add commands stuff and save the text into file;
    Test UserInput;

    if(OFILE.is_open())
    {
    std::cin>>UserInput; // so we take input we validify it as well check validity by Test.Valid
    if(UserInput.Valid)
    {
        OFILE<<UserInput;
    }
    }else {std::cout<<"file could not be opened;"<<std::endl;}
    
    std::cin.get();
}

std::istream& operator>>(std::istream& InStream,Test& InTest)
{ // we gon create string then copy over that string to Test.Message because istreams doesnt do dynamics for char*
    std::string TempString;
    if(InStream.getline(InStream,TempString,NAME_MAX,'\n'))
    { // ok so just use peek() and get() not try and work with getline() and stuff cuz ur goign to get overwhelemed quickly

    }
    InStream>>InTest.Message>>InTest.UserInt;
    if(!(InStream.fail()))
    {
        InTest.MultiBy2 = InTest.UserInt * 2;
        std::cout<<"Amazing It worked "<<std::endl;
        InTest.Valid = true;
    }else
    {
        InStream.clear(); // flushes the istream;
        InStream.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cerr<<"Invalid Input"<<std::endl;
        InTest.Valid = false;
    }
    return InStream;
}

std::ostream& operator<<(std::ostream& OStream,Test& InTest)
{// what  i want it to be like Name int int;
    OStream<<"Name : "<<InTest.Message<<" UserInt : "<<InTest.UserInt<<" MultiBy2 : "<<InTest.MultiBy2<<std::endl;
    return OStream;
}