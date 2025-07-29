#include "Task.h"
#include <fstream>
#include <string>

void InputStart(Choices& InputChoice)
{
        Log::LogMessage("Choose a Number 0-3");
        Log::LogMessage("0.Close");
        Log::LogMessage("1.Add Task");
        Log::LogMessage("2.Delete Task");
        Log::LogMessage("3.Mark Tasks Complete or Undone");
        Log::LogMessage("4.Show Tasks");
        int input;
        std::cin>>input;
        InputChoice = static_cast<Choices>(input);
        FlushIstream();
}

void MarkTasks(std::vector<Task>& tasks)
{
    // take in line number and open file in trunc mode and make 0 - > 1
    ShowTasks(tasks);
    int LineNumber{};

    Log::LogMessage("Enter Line Number 0 < n < size");
    
    if(std::cin>>LineNumber)
    {
        if(SantifyLineNum(LineNumber,tasks))
        { // if correct line number
            // Flip the task 
            bool &Done = tasks[LineNumber - 1].done;
            FlipBool(Done);

            std::ofstream File;
            File.open("./data/tasks.txt",std::ios::trunc);
            
            if(File.is_open())
            {
                for(auto task : tasks)
                {
                    File<<task;
                }
            }else
            {
                Log::LogMessage("File could not be opened for writing");
            }
        }else
        {
            Log::LogMessage("Enter a valid LineNumber");
        }
    }
}

void DeleteTask(std::vector<Task>& tasks)
{
    ShowTasks(tasks);
    int LineNumber{};

    Log::LogMessage("Enter Line Number 0 < n < size");
    
    if(std::cin>>LineNumber)
    {
        if(SantifyLineNum(LineNumber,tasks))
        { // if correct line number
            
            tasks.erase(tasks.begin() + LineNumber - 1);

            std::ofstream File;
            File.open("./data/tasks.txt",std::ios::trunc);
            
            if(File.is_open())
            {
                for(auto task : tasks)
                {
                    File<<task;
                }
            }else
            {
                Log::LogMessage("File could not be opened for writing");
            }
        }else
        {
            Log::LogMessage("Enter a valid LineNumber");
        }
    }
}

bool SantifyLineNum(int& LineNum,std::vector<Task>& tasks)
{ // num > 0 and less than size
    if(LineNum > 0 && LineNum <= tasks.size())
    {
        return true;
    }else
    {
        return false;
    }
}


std::ostream& operator<<(std::ostream& _ostream,Task& _Task)
{
    if(_Task.done)
        {
                _ostream<<"1|"<<_Task.description<<'\n';
        }else
        {
                _ostream<<"0|"<<_Task.description<<'\n';
        }
    return _ostream;
}

void FlipBool(bool& _Bool)
{
            if(_Bool)
            {
                _Bool = false;
            }else
            {
                _Bool = true;
            }
}
void LoadTasks(std::vector<Task>& tasks)
{
    std::ifstream InFile("./data/tasks.txt");
    tasks.clear();
    
    if(InFile.is_open())
    {
        while(true) // run untill eof is not reached or the eof bit is not set
        {
            std::string Description;
            bool done{};    
            InFile>>done; // gets 0 or 1; 
            
            InFile.ignore(1); // extracts and discards 1 char |
            std::getline(InFile,Description); // extracts the description untill \n char
                    
            if( InFile.fail() )    {   break;  } // also checks EOF
            // if successful add task 
            Task _Task{Description, done};
            tasks.push_back(_Task);
        }
    }else
    {
        std::cerr<<"error occured File could not be read"<<std::endl;
    }
}

void ShowTasks(std::vector<Task>& tasks)
{ // loadTasks and then loop over Vector and show all of them
    LoadTasks(tasks);
    for(auto task : tasks)
    {
        if(task.done)
        {
                std::cout<<"[X] "<<task.description<<std::endl;
        }else
        {
                std::cout<<"[ ] "<<task.description<<std::endl;
        }
    }
}


void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);

    Task newTask{description, false}; // false = not done
    tasks.push_back(newTask);         // add to in-memory list

    std::ofstream file("./data/tasks.txt", std::ios::app); // append mode
    if (file.is_open()) {
        file << "0|" << description << '\n'; // format: 0|task description
        file.close();
    } else {
        std::cerr << "Failed to open tasks.txt for writing.\n";
    }
}


void FlushIstream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // std::cerr<<"[Input Error : Try Again ]"<<std::endl;
}