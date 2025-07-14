class SudokuBoard
{
    public :
    char* Board[9]; // - > each Board[n] is a box of 9 chars Board[9][9] so basically each
    // ptr is a row each 1st char of a row combined is column
    void ConstructBoard();
    void SantifyBoard();
    void GenerateRandomBox(int& _iteratorbox);
    void CalculateMissingOfBox(int& BoxRow,int& BoxCol,char* MissOfBox,int& BoxIterator);
    int GetRow(const int& _Position);
    int GetColumn(const int& _Position);
    char RandomPossChars[9] = {'1','2','3','4','5','6','7','8','9'};
};
