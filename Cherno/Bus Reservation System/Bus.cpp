#include "Bus.h"

BusManager::BusManager(){
    // i want to load the buses from a file and thats why i used heap but since i dont have that skill rn lets hardcode
    
    this->size = 2;
    this->Buses = new char*[size]; // since char* is a pinter u cant just directly say point to this block of memory without sort of specifying the size and stuff;
    CreateAndAppendStringCnst__CharPtr("California",this->Buses[0]);
    CreateAndAppendStringCnst__CharPtr("California",this->Buses[1]); // or a for loop would be faster than copying two lines
};

void CreateAndAppendStringCnst__CharPtr(const char* Constant,char*& Ptr)
{
    short ConstSize = CalculateSizeOfCharArr(Constant);
    Ptr = new char[ConstSize]; // allocated now u need to copy it
    StringCopy(Constant,Ptr);
    std::cout<<Ptr<<std::endl;
}

void StringCopy(const char* Char_Read ,char* Write)
{
    char* StartingPos = Write;
  // [ 0 ,0 0 ,0 ,0] [ B ,  U , S , \0] // what ur doing is checking if the starting array the one im going towrite to
  // has ended we already know that they will be the same so dc abt that
    while(*Char_Read != '\0') // if this false then u have reached the end of the Char_read arr
    {
        *StartingPos = *Char_Read;
        Char_Read++;
        StartingPos++; // so u can modify the pointer with const char* but not the char; so say char[0] is accessing
    }
    *StartingPos = '\0'; // adding the null char
}

void BusManager::ShowBuses_Dest(CharBuffer& UserDestChoice)
{
    int HardcodedBusAvailable[2];
    HardcodedBusAvailable[0] = -1;
    HardcodedBusAvailable[1] = -1;

    for(int i = 0;i<this->size;i++)
    {
        if(CheckUser_Char_Congruence(UserDestChoice,this->Buses[i]))
        {
            if(HardcodedBusAvailable[0] != -1)
            {
                HardcodedBusAvailable[1] = i;
            }else{
                HardcodedBusAvailable[0] = i; 
            } // i know i know very good logic im amazing i know i know
        }
    }
    for(int i = 0;i < 2;i++)
    {
        if(HardcodedBusAvailable[i] != -1)
        {
        std::cout<<"Bus "<<HardcodedBusAvailable[i]<<" : "<<this->Buses[HardcodedBusAvailable[i]]<<std::endl;
        }
    }
};
    
std::ostream& operator<<(std::ostream& ostream,CharBuffer& Buffer)
{
    ostream<<"String : ";
    ostream<<Buffer.Char<<std::endl;
    ostream<<"String Size : "<<Buffer.size<<std::endl;
    ostream<<"String Capacity : "<<Buffer.capacity<<std::endl;
    return ostream;
}

std::istream& operator>>(std::istream& istreamRead,CharBuffer& Buffer)
{ // Given : -the char ur going to write to,- the input stream so u have to use getline() as its going only write in the caracters of the size u give it
    
    istreamRead.getline(Buffer.Char,Buffer.capacity);

    //^^ if this fails for example it couldnt write over all the user data or the user inputted something other than char(or any data type not specified) then it marks the inputstream a failbit

    if(istreamRead.fail())
    { // failbit is in istream hence some funky stuff happened refer to the above commend
        istreamRead.clear(); // clears the whole istream
        istreamRead.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores every single character left in the stream and flush it untill it hits delim char "\n" which means a new line so new other input 
        std::cerr<<"very cool user u think we're stupid? input something between size 1 - "<<Buffer.capacity<<std::endl;
        std::cout<<Buffer;
    } else
    { // it didnt fail set size
        Buffer.size = 0;
        while((Buffer.Char[Buffer.size] != '\0') && Buffer.size < Buffer.capacity + 1) // stop at 1 less
        {
            Buffer.size++; 
        } 
    } // by default '' represent a char while "" represent chars so when chekcing for types and stuff tis is needed to know
    return istreamRead;
} // ok so no need to have a wrapper just make it secure that was the goal <---


int CalculateSizeOfCharArr(const char* text)
{ // text in this sense is actually always going to be filled up with proper chars;
    int size = 0;
    while(text[size] != '\0')
    {
        size++; // loops untill it doesnt hit termin char
    }
    return size;
}

bool CheckUser_Char_Congruence(const CharBuffer& UserChoice,const char* TextToCompare)
{ // /0 indicates last char  S T R L S /0 _ T S R F /0
    // check size if size of text is more than size of choice then return false;
    // their sizes have to be the same for this to be true -_- hence we first compare their sizes and
    // then we start checking all chars and if it succeeds then we return true at end; 
    // iterate and cuz we know that usrchoice's size is bigger than we keep checking for if its false untill we hit
    // delim char \0

    std::cout<<"TextSize : "<<CalculateSizeOfCharArr(TextToCompare)<<" , UserSize : "<<UserChoice.size<<"\n";    
    if(!(CalculateSizeOfCharArr(TextToCompare) == UserChoice.size))
        {
            return false;
        }

    for (int i=0;i<UserChoice.size;i++)
    {
        
        std::cout<<*(UserChoice.Char + i)<<","<<*(TextToCompare + i)<<"\n";
         if(!(*(UserChoice.Char + i) == *(TextToCompare + i)))
        { // means they are not the same character
            return false; 
        }
    }
    return true;
}

void Log(const char* literal)
{
    std::cout<<literal<<std::endl;
}   