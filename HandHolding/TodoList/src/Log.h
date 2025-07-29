#include <iostream>
#ifndef LOG_H
#define LOG_H
class Log
{
    
    public :
    Log() = delete; // no constructor
    static void LogMessage(const char* Message);

};
#endif