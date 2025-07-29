#include "Log.h"
#include <vector>
#include <limits>

struct Task {
    std::string description;
    bool done;
};

enum Choices : unsigned char
{
    ChoicesClose = 0,ChoicesAdd,ChoicesDelete,ChoicesMark,ChoicesShow
};

void addTask(std::vector<Task>& tasks);
void ShowTasks(std::vector<Task>& tasks);
void MarkTasks(std::vector<Task>& tasks);
void LoadTasks(std::vector<Task>& tasks);
void FlipBool(bool& _Bool);
void DeleteTask(std::vector<Task>& tasks);
bool SantifyLineNum(int& LineNum,std::vector<Task>& tasks);

std::ostream& operator<<(std::ostream& _ostream,Task& _Task);

// Input Guide
void InputStart(Choices& _Choice);
void FlushIstream();