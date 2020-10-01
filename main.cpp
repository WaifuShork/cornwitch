#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <limits>
#include <windows.h>
#include <fstream>
#include <vector>
#include "game-data.cpp"

std::string getFileContents (std::ifstream&);  //Gets file contents
std::ifstream Reader("./graphics/logo.txt");
std::ifstream Reader2("./graphics/choice.txt");

char ch;
int main(int argc, char *argv[])
{
    #pragma region Window
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1700, 1080, true);
    system("Color 03");
    #pragma endregion

    std::string Art = getFileContents(Reader);
    std::cout << Art << "\n"; 
    Reader.close();

    std::string Art2 = getFileContents(Reader2);
    std::cout << Art2 << "\n";
    Reader.close();

    std::cin >> ch;
    switch(ch)
    {
        case '1':
            system("cls");
            DrawCharacter();
            break;
        
        case '2':
            return 0;
    }
    CharacterStats();
    DrawIntro();
    SceneOne();
}


// File system for drawing to the screen
std::string getFileContents(std::ifstream& File)
{
    std::string Lines = "";

    if (File)
    {
        while(File.good())
        {
            std::string TempLine;
            getline (File, TempLine);
            TempLine += "\n";

            Lines += TempLine;
        }
        return Lines;
    }
    else
    {
        return "Error File does not exist.";
    }
}
