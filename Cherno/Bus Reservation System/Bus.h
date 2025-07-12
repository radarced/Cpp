#ifndef BUSMNGER_H
#define BUSMNGER_H
#include <iostream>
#include <limits>

struct CharBuffer
{
    char* Char;
    int size;
    int capacity;
};

void Log(const char* literal);
bool CheckUser_Char_Congruence(const CharBuffer& UserChoice,const char* TextToCompare);
int CalculateSizeOfCharArr(const char* text);
std::ostream& operator<<(std::ostream& ostream,CharBuffer& Buffer);
std::istream& operator>>(std::istream& istreamRead,CharBuffer& Buffer);
int CalculateSizeOfCharArr(const char* text);
bool CheckUser_Char_Congruence(const CharBuffer& UserChoice,const char* TextToCompare);
void Log(const char* literal);
void CreateAndAppendStringCnst__CharPtr(const char* Constant,char*& Ptr);
void StringCopy(const char* Char_Read ,char* Write);

class BusManager
{
    public:

    BusManager();
    void ShowBuses_Dest(CharBuffer& UserDestChoice);

    private :

    char** Buses;
    int size;
};

#endif