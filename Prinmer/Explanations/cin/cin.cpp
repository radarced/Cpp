#include <iostream>
#include <limits>
#include <string>

void ReadMultiple(char*& Command,int& Type);
void ReadWCin(char* Message);

class Command
{   
    public :
    friend std::istream& operator>>(std::istream& InStream,Command& InCommand);
    Command() : m_Parameter(0){};
    Command(std::istream& Is) { Is>> *this;} // so it accepts an istream and then it basically passes that istream to that friend operator overloader;
    friend std::ostream& operator<<(std::ostream& Ostream,Command& InCommand);
    private :
    std::string m_Cmd;
    int m_Parameter;
};

int main()
{ // so since cin is an object it has to get initialized so i think iostream does that automatically
 // reading multiple inputs;
    int InputParam;
    Command user_Command;

    // ReadMultiple(InputCommand,InputParam);
    // ReadWCin(Message);
    std::cin>>user_Command;
    std::cout<<user_Command;
    std::cin.get();
}


// i havent init the char* but i think that cin takes care of it; i still dont underswtsand this >> << nonsense
void ReadMultiple(char*& Command,int& Type)
{
    std::cout<<"Enter Command Params"<<"\n";
    if(std::cin>>Command>>Type)
    {
    std::cout<<Command<<Type<<std::endl;
    }else
    {
        std::cout<<"Some Params are not valid ?"<<std::endl; // <-- flushes the output stream
    }
}

void ReadWCin(char* Message)
{
    std::cout<<"Enter Message"<<"\n";
    if(std::cin.getline(Message,'\n')) // ok so this is one of given methods so A char* and a delim char;
    // and only chars work with getline()
    {
        std::cout<<Message<<"\n";
    }
}

std::istream& operator>>(std::istream& InStream,Command& InCommand)
{
    std::cout<<"Enter Command Params"<<"\n";
    InStream>>InCommand.m_Cmd>>InCommand.m_Parameter; // takes input like cmd parameter
    // if the wrong data type is passed or if the range is not met then a failbit or eofbit is set which can be detected by .fail() on std::istream;
    if(InStream.fail())
    {
        InStream.clear(); // sets it state back to normal instead of failing;
        InStream.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // set all data in the stream upto \n to alwayus ignore <- meaning this data is uselss     
        std::cerr<<"u dumbo input something like cmd param"<<std::endl;
    } 
    else
    {
        std::cout<<".. it assigned input - > Command"<<std::endl;
    }

    return InStream;
}

std::ostream& operator<<(std::ostream& Ostream,Command& InCommand)
{
    Ostream<<"Command : "<<InCommand.m_Cmd<<" Parameter : "<<InCommand.m_Parameter<<std::endl;
    Ostream<<"Supp Angle : "<<180 - InCommand.m_Parameter<<std::endl; 
    return Ostream;
}