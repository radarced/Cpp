enum Index
{
    Name_Index,Id_Index,Grade1_Index,Grade2_Index,Total_Index,NonGrade_Index = 2
};

class StudentData
{
    private :
    char* Name;
    int Id{};
    
    float Grades[2]; // so [0] is Maths [1] is Physics for now;
    bool GradesValid = false;
    
    bool valid = true; // indicator of if the input given has been so far;
    bool ComponentsValidity[4] = {}; // [0,1,2,3] = [Name,Id,Grades[0],Grades[1]] // if individual comps have been set

    public :
    StudentData() {ComponentsValidity[Index::Name_Index] = true;};
    // void AddName(const char* _Name);
    ~StudentData(){delete Name;};
    void AddGrade();
    void IntInput();
    void AddId(); // if id already set - > assume its a grade and add that;
    bool Valid(){return valid;}
};

void FlushCin();
