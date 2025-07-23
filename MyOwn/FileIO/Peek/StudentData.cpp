#include "StudentData.h"
#include <limits>
#include <iostream>

void StudentData::IntInput()
{
    if(this->ComponentsValidity[Index::Id_Index])
    { // id already set;

        //if( Grades are set then return else -> set grade)
        if(!(this->GradesValid))
        { // if not valid
            this->AddGrade();
        }else
        { // so its looping over again and again since ofc theres  data in istream thats not extracted;
            std::cout<<"Id and Grades have already been set;"<<std::endl;
            // since we know that grades and id have been set we just need to check if name is set if so then just flush out the istream;
            this->valid = false; // we have set it so tbh it would be better to have some bool construced varibale;
            if(this->ComponentsValidity[Index::Name_Index])
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"[Success : successfully Set StudentData ]"<<std::endl;
            }
        }
    }else
    {
        this->AddId();
        this->ComponentsValidity[Index::Id_Index] = true;
    }
    
}

void StudentData::AddId()
{
    int IdInput{};
    if(std::cin>>IdInput) // specifically checks only int is in istream so stuff like 123abc is going to set a failbit
    {
        this->Id = IdInput;
    if(std::cin.peek() == ' ') // whitespace char then use manipulator;
        {
        std::cin>>std::ws;
        }
    std::cout<<"You Entered The Id : "<<IdInput<<std::endl;
    } 
    else
    {
        FlushCin();
        this->valid = false;
        std::cerr<<"[Error : U inputted invalid Number dont input 123.abc just 123 ]"<<std::endl;
    }
}

void StudentData::AddGrade()
{
    float GradeInput{};
    if(std::cin>>GradeInput) // TODO : add && and check if GradeInput is in its range;
    {
        if(std::cin.peek() == ' ') // whitespace char then use manipulator;
        {
        std::cin>>std::ws;
        }
    std::cout<<"You Entered The Grade : "<<GradeInput<<std::endl;
    } 
    else
    {
        FlushCin();
        this->valid = false;
        std::cerr<<"[Error : U inputted invalid decimalNumber dont input 123abc just 123.32]"<<std::endl;
        return;
    }
    size_t NofValid{};
    for(size_t i = Index::Grade1_Index;i < Total_Index;i++)
    {
        if(this->ComponentsValidity[i])
        { // already set;
            NofValid++;
            continue;
        }else
        {
            this->Grades[i - Index::NonGrade_Index] = GradeInput;
            this->ComponentsValidity[i] = true;
            NofValid++;
            break;
        }
    }
    if (NofValid == 2)
    {
        this->GradesValid = true;
    }
}

void FlushCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cerr<<"[Input Error : Try Again ]"<<std::endl;
}