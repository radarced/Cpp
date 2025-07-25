#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <cstring> // for strcpy

#define NAME_MAX 100

struct Test {
    char* Message = nullptr;
    int UserInt;
    int MultiBy2;
    bool Valid = false;
};

std::istream& operator>>(std::istream& InStream, Test& InTest);
std::ostream& operator<<(std::ostream& OStream, Test& InTest);

int main() {
    std::ofstream OFILE("File.txt", std::ios::app);

    if (!OFILE.is_open()) {
        std::cout << "file could not be opened;" << std::endl;
        return 1;
    }

    Test UserInput;

    std::cin >> UserInput;
    if (UserInput.Valid) {
        OFILE << UserInput;
    }

    delete[] UserInput.Message; // free heap memory!
    std::cin.get();
    return 0;
}

std::istream& operator>>(std::istream& InStream, Test& InTest) {
    std::string TempString;

    std::cout << "Enter Name: ";
    std::getline(InStream, TempString);

    std::cout << "Enter Integer: ";
    InStream >> InTest.UserInt;

    if (!InStream.fail()) {
        // Copy to heap
        size_t len = TempString.length();
        InTest.Message = new char[len + 1];
        std::strcpy(InTest.Message, TempString.c_str());

        InTest.MultiBy2 = InTest.UserInt * 2;
        std::cout << "Amazing! It worked.\n";
        InTest.Valid = true;
    } else {
        InStream.clear();
        InStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid Input\n";
        InTest.Valid = false;
    }

    return InStream;
}

std::ostream& operator<<(std::ostream& OStream, Test& InTest) {
    OStream << "Name: " << InTest.Message
            << " UserInt: " << InTest.UserInt
            << " MultiBy2: " << InTest.MultiBy2 << "\n";
    return OStream;
}
// Chatgpt fixed this not u;