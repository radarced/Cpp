#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Log.h"
#include "Task.h"
#include <limits>



int main() {
    std::vector<Task> tasks;

    bool running = true;
    Choices Choice;
    
    while (running)
    {
        InputStart(Choice);
        std::cout<<Choice;
        switch(Choice)
        {
            case ChoicesClose :
                running = false;
            break;

            case ChoicesAdd :
            addTask(tasks);
            break;

            case ChoicesDelete :
                DeleteTask(tasks); 
            break;


            case ChoicesMark :
                MarkTasks(tasks);
            break;

            case ChoicesShow :
                ShowTasks(tasks);
            break;
        }
    }
    return 0;
}
