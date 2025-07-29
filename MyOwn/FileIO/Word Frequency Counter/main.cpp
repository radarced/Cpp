#include <fstream>
#include <iostream>
#include <unordered_map>
#include <limits>
#include <cctype> // contains bunch of modifers and checkers of char

// input.txt - > read each word from it - > tell its count;
using std::cin;
typedef std::unordered_map<std::string,int> WordFrequency;// string = word int = count;

void ExtractFStream(std::ifstream& _Ifstream,std::ofstream& _Ofstream,WordFrequency& _WordFrequency);
void AppendText(std::ofstream& _Ofstream);
void LogMessage(const char* Message);
void PrintCount(WordFrequency _WordMap);
void SantifyString(std::string& Word);

int main()
{

    std::ifstream Ifstream("Input.txt",std::ios::in); 
    std::ofstream Ofstream("Input.txt",std::ios::app);
    
    WordFrequency WordMap;

    if(Ifstream.is_open())
    { // if it exists and i have access to it;
        ExtractFStream(Ifstream,Ofstream,WordMap);         
    }else
    { // create one and accept data into it 
        
        if(Ofstream.is_open())
        {
            LogMessage("the File was not created Append Text into it ");
            AppendText(Ofstream);
        }else
        {
            std::cerr<<" File Could not be opened [Exiting Program]"<<std::endl;
            return 1;
        }  
        
    }

    cin.get(); // wait for input;

}

void ExtractFStream(std::ifstream& _Ifstream,std::ofstream& _Ofstream,WordFrequency& _WordFrequency)
{

    std::string Word;
    while(_Ifstream>>Word) // like cin ignores whitespaces and reads untill EOF
    {
        SantifyString(Word);
        if(_WordFrequency.find(Word) != _WordFrequency.end())// syntax if[el] exists ifMap[] != Map.end
        {
            _WordFrequency[Word]++; // adding Count
        }else
        { // before adding santify the word;
            _WordFrequency[Word] = 1; //add it to the map;
        }
    }

    PrintCount(_WordFrequency);

    char x{};
    LogMessage("Would u Like to Appen Text if so continue with P");
    if(cin>>x)
    {
    if(x == 'P' || x=='p')
    {
        cin.clear();

        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');        

        AppendText(_Ofstream); // idc about so many pass downs its all references   
    }            

    }else 
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');        
    }
}

void AppendText(std::ofstream& _Ofstream)
{
        std::string InputText{};
        std::getline(cin,InputText,'\n'); // extract untill \n into InputText;
        // inputtext has the input extracted in it

        if(_Ofstream.is_open())
        {
            _Ofstream<<InputText<<std::endl;
        
        }else
        {
            LogMessage("something funky is going on ");
        
        }
}

void LogMessage(const char* Message) // i understand this ptr* andchar constant* dffrence now
{ // u cant assign anything to it cuz const
    std::cout<<Message<<std::endl;
}

void PrintCount(WordFrequency _WordMap)
{
    for (auto it = _WordMap.begin();it != _WordMap.end();it++)
    { // so idk much about it here i suppose its a pair?
        if(it->second > 1)
            std::cout<<"Word : "<<it->first<<"\t"<<"Count : "<<it->second<<std::endl;
    }   
}

void SantifyString(std::string& Word)
{// example "EXAMPLE<,,>>>" - > example
    for(auto it = Word.begin();it != Word.end();)
    {
        // *it;  accessed oook so this it is the pointer to my char so dereference

        if(ispunct(*it))
        {
            it = Word.erase(it);
            continue;
        }else
        if(isupper(*it))
        {
            *it = static_cast<char>(tolower(*it));
        }
        it++;
    }
}