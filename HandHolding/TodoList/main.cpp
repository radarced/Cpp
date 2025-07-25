#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Task {
    std::string description;
    bool done;
};

void addTask(std::vector<Task>& tasks);
void ShowTasks(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    addTask(tasks);
    ShowTasks(tasks);
    return 0;
}

void ShowTasks(std::vector<Task>& tasks)
{
    std::ifstream InFile("tasks.txt");

    if(InFile.is_open())
    {
        while(true) // run untill eof is not reached or the eof bit is not set
        {
            std::string Description;
            bool done{};    
            InFile>>done; // gets 0 or 1; 
            
            InFile.ignore(1); // extracts and discards 1 char |
            std::getline(InFile,Description); // extracts the description untill \n char

            if( InFile.fail() )    {   break;  }
            
            if(done)
            {
                std::cout<<"[X] "<<Description<<std::endl;
            }else
            {
                std::cout<<"[ ] "<<Description<<std::endl;
            }
        }
    }else
    {
        std::cerr<<"error occured File could not be read"<<std::endl;
    }
}


void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    Task newTask{description, false}; // false = not done
    tasks.push_back(newTask);         // add to in-memory list

    std::ofstream file("tasks.txt", std::ios::app); // append mode
    if (file.is_open()) {
        file << "0|" << description << "\n"; // format: 0|task description
        file.close();
    } else {
        std::cerr << "Failed to open tasks.txt for writing.\n";
    }
}
