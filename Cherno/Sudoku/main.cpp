#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()
#include <iostream>
#include "SudokuBoard.h"

// so we have our board now we need to validify each Box and change it;
// how do we do that?
// theres three rules to sudoku :
// 1. No repeating char in a row;
// 2. No repeating char in a column;
// 3. No repeating char in a BoxContainer;
// im thinking we iterate over each boxContainer and first check all of these rules and then store the possible nums;
// do u have to check Rules for each position?
// i think yes and this sort of randomGenerated might be useless;
// we iterate over first boxctr we check if 1st box is valid or not (rules) then what to do if valid or not valid;
// valid : we do nothing;
// not valid : we change what is missing in one of the pair ( row , col , box )
// lets look at it with the worst possible given randomBox so lets say 1,1,1,1,1,1,1 all box are 1;
// i think its better to first sort out the boxes rather than validiting one pair like row or col just do boxctr first 
// so it goes like this 
// by checking i mean : noting the char down and checking if its repeating in the pair;
// u go to 1st boxctr cehck its 1stpos and check all rules if the missing of rows and the missing of cols and the missing
// of box are congruent then use that missing if not then use the box missing and move on
// now in 2nd pos u have to not use the pos that uve already validified so a validified arr ; MissOfArr;MissOfCol;MissOfBox
// goal is to validify AT least the box pair then move on to the next box and repeat;

int main()
{
    srand(time(NULL));
    SudokuBoard _SudoBoard;
    _SudoBoard.ConstructBoard();

}

void SudokuBoard::ConstructBoard()
{
    // we wanbt to allocate 9 bits of memory and make 
    // Board[n] point to that;

    for( int i = 0; i < 9;i++)
    {
        Board[i] = new char[9]; // does the job of alloc,point
        this->GenerateRandomBox(i);
    } // so now we have Board[n] - > boxes of 9 char
    this->SantifyBoard();
}

void SudokuBoard::GenerateRandomBox(int& _iteratorContainerbox)
{
    int iterationcount=0;
    for(int i = 0;i < 9;i++)
    {
    iterationcount++;
    int Random = (rand() % 9); // 0-8
    this->Board[_iteratorContainerbox][i] = this->RandomPossChars[Random];
    if(i == 0) // first char this only for visual purpose
    {
        std::cout<<"{ "<<this->Board[_iteratorContainerbox][i]<<" , ";
        continue;
    }else if(i==8) // last char
    {
        std::cout<<this->Board[_iteratorContainerbox][i]<<" }"<<"XXXXXX Chars in first Box : "<<iterationcount<<std::endl;
        break;
    }
    std::cout<<this->Board[_iteratorContainerbox][i]<<" , ";
    }
};
// RULES :
// theres three rules to sudoku :
// 1. No repeating char in a row;
// 2. No repeating char in a column;
// 3. No repeating char in a BoxContainer;


// so it goes like this 
// by checking i mean : noting the char down and checking if its repeating in the pair;
// u go to 1st boxctr cehck its 1stpos and check all rules if the missing of rows and the missing of cols and the missing
// of box are congruent then use that missing if not then use the box missing and move on
// now in 2nd pos u have to not use the pos that uve already validified so a validified arr ; MissOfArr;MissOfCol;MissOfBox
// goal is to validify AT least the box pair then move on to the next box and repeat;
void SudokuBoard::SantifyBoard()
{ // so we're iterating over the boxctrs and their boxes so double for loops;
    char MissingOfArr[9];
    char MissOfCol[9];
    char MissOfBox[9];
    int Col;
    int Row;
    int BoxRow;
    int BoxCol;

    for(int BoxCtrIterator = 0;BoxCtrIterator < 9;BoxCtrIterator++)
    { // boxctr
        // MissOfBox is calculated here;
        BoxRow = GetRow(BoxCtrIterator);
        BoxCol = GetColumn(BoxCtrIterator);
        this->CalculateMissingOfBox(BoxRow,BoxCol,MissOfBox,BoxCtrIterator);

        for(int BoxIterator = 0;BoxIterator < 9;BoxIterator++)
        { // box
            char CurrentBox = this->Board[BoxCtrIterator][BoxIterator]; // current char Box;3 < BoxIterator < 7
            /* we want to get missing of Rows first and store them in an array then do the same with
            column rows and 
            */ 
            // so we trying to find missing of Rows and then Missing of Cols
            // so rn ill just tell the missing and brute force this but later on ill
            // set some kind of state of them so i remember the valid ones and go off of that 
            // so something like a function overload?
            
            Row = GetRow(BoxIterator);

        }
    }
}
// BoxRow and BoxCol is for checking for validified ones
void SudokuBoard::CalculateMissingOfBox(int& BoxRow,int& BoxCol,char* MissOfBox,int& BoxCtrIterator)
{
    for (int Boxiterator = 0;Boxiterator < 9;Boxiterator++)
    {
        // in a 1d 9 els array how do u check if there are repeated elements
    }
}

 // the getRow and GetCol works for both the Boxes and the chars inside the boxes since both are 3x3 grids
int SudokuBoard::GetColumn(const int& _Position)
{
    unsigned Col = 0;
    unsigned WrapsAround = _Position % 3;
    if (WrapsAround == 1)
    {
        Col = 1;
    }else if(WrapsAround == 2)
    {
        Col = 2;
    }
    return Col;
}

int SudokuBoard::GetRow(const int& _Position) // function assumes its an 3x3 grid as thats what im wroking with
{
    unsigned Row = 0;
    if (_Position > 5)
    {
        Row = 2;
    }else if(_Position > 2)
    {
        Row = 1;
    }
    return Row;
}