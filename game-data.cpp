#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <limits>
#include <windows.h>
#include <fstream>
#include <vector>

std::string enemyName;
std::string characterName;
std::string fateName, fateMessage;

char fateChoice, weaponChoice, pathChoice;
std::string weaponName;
bool hasDagger = false, hasStaff = false;
std::string input;
std::string pathName;
float staff = 70;
float dagger = 50;
float health = 100;
float weaponDamage;

char choice;

void DrawIntro();
void SceneOne();
void SceneOneValley();
void SceneOneMountain();
void MarketScene();

std::string getFileContents (std::ifstream&);


void DrawCharacter()
{   
    system("Color 0D");
    std::ifstream cReader("./graphics/character-creation.txt");
    std::string cArt = getFileContents(cReader);
    std::cout << cArt << "\n"; 
    cReader.close();

    std::cout << "       Please choose your name!\n\n";
    std::cin >> characterName;

    std::cout << "\n\n";
    std::cout << "       You smell flowers... its sweet and comforting, reminds you of the mountains, suddenly\n\n";
    std::cout << "       you catch a drift of hardened metal and bones... something powerful.\n\n";
    std::cout << "       1. Flowers         2. Artifacts\n\n";
    std::cin >> fateChoice;
    
    std::cout << "       Mmmm interesting...choice.\n\n";
    
    std::cout << "       Please choose your weapon!\n\n";
    std::cout << "       1. Dagger          2. Staff\n\n";
    std::cin >> weaponChoice;

    if (weaponChoice == '1')
        {
            hasDagger = true;
            weaponName = "Dagger";
        }
    else if (weaponChoice == '2')
    {
        hasStaff = true;
        weaponName = "Staff";
    }

        // ----------------------------

    if (fateChoice == '1')
    {
        fateName = "Flowers";
        fateMessage = "The Flowers shall empower you and grant you great luck throughout your journey.";
    }
    else if (fateChoice == '2')
    {
        fateName = "Artifacts";
        fateMessage = "Mmmmm, you can feel the Artifact strengthening you, but something feels off..";
    }
    
    std::cout << "\n\n";
    system("cls");
}

void CharacterStats()
{
    std::ifstream sReader("./graphics/player-stats.txt");
    std::string sArt = getFileContents(sReader);
    std::cout << sArt << "\n";
    sReader.close();

    if (weaponName == "Staff" && fateName == "Artifacts")
    {
        weaponDamage = 42;
    }
    else if (weaponName == "Staff" && fateName == "Flowers")
    {
        weaponDamage = staff + 28;
    }

    if (weaponName == "Dagger" && fateName == "Artifacts")
    {
        weaponDamage = 30;
    }
    else if (weaponName == "Dagger" && fateName == "Flowers")
    {
        weaponDamage = 70;
    }

    if (fateName == "Flowers")
    {
        health = 200;
    }
    if (fateName == "Artifacts")
    {
        health = 70;
    }

    std::cout << "  ======================================= \n\n";
    std::cout << " | Character Name: " << characterName << "\n\n";
    std::cout << " | Health: " << health << "\n\n";
    std::cout << " | " << weaponName << " Damage: " << weaponDamage << "\n\n";
    std::cout << " | Fate Choice: " << fateName << "\n\n";
    std::cout << "  ======================================= \n\n";
    std::cout << " Best of luck on your journey.. " << characterName << "\n\n";
    std::cin >> input;
    system("cls");
}

void DrawIntro()
{
    system("Color 03");
    std::cout << "\n\n\n\n\n";
    std::cout << "                           Welcome to CornWitch. This is a story about a young witch, on a journey to go to the store and buy corn.\n\n";
    std::cin.get();

    std::cout << "                           It's mid summer, sometime in July. " << characterName << "'s mother asked if she would make a trip to the store.\n\n";
    std::cin.get();


    std::cout << "                           "<< characterName << " reluctantly sighed before agreeing to her mothers request: 'What is it you need from the store?'\n\n";
    std::cout << "                                                                    -she asked her mother in as polite of tone as possible-\n\n";
    std::cin.get();



    std::cout << "                           Her mother returned happily: 'We're all out of corn, I was hoping you could fetch a few kilos worth!'\n\n";
    std::cout << "                                                                                               -in such a chiming tone-\n\n";
    std::cin.get();

    std::cout << "                           " << characterName << " noted down her mothers request and began to get ready to leave for the house.\n\n";;
    std::cin.get();

    std::cout << "                           Press enter to continue...\n";
    std::cin.get();
    system("cls");
}


void SceneOne()
{
    std::cout << "                           You're leaving the house and are thinking about which path to take.\n\n";
    std::cout << "                                                   -should I take the mountain or valley-\n\n";
    std::cout << "                           1. Mountain    2. Valley\n\n";
    std::cin >> pathChoice;

    if (pathChoice == '1')
    {
        pathName = "Mountain"; 
        system("cls"); 
        SceneOneMountain();
    }
    if (pathChoice == '2')
    {
        pathName = "Valley";
        system("cls");
        SceneOneValley();
    }
}

void SceneOneMountain()
{
    system("Color 09");
    srand (time(NULL));
    int enemy = std::rand() % 2;
    if (enemy == 0)
    {
        enemyName = "Goblin";
    }
    else if (enemy == 1)
    {
        enemyName = "Demon";
    }
    else if (enemy == 2)
    {   
        enemyName = "Troll";
    }

    std::cout << "                           You begin to make your way in the direction of the mountains.\n\n";
    std::cin.get();
    std::cout << "                           you've always loved going through the mountains and feeling the fresh breeze in the higher altitudes\n\n";
    std::cin.get();
    std::cout << "                           even if the walk is a bit longer, the scenery is still stunning, tall dark green trees, and crisp flowing rivers..\n\n";
    std::cin.get();
    std::cout << "                           midway up the up you spot a " << enemyName << "....\n\n";
    std::cin.get();
    std::cout << "                           you quietly think to yourself what to do, before approaching the " << enemyName << ".\n\n";
    std::cin.get();
    std::cout << "                           The " << enemyName << " spots you and is quickly alerted.\n\n";
    std::cin.get();
    std::cout << "                           Do you wish to fight or run past?\n\n";
    std::cout << "                           1. Run    2. Fight\n\n";
    std::cin >> choice;

    if (choice == '1')
    {
        srand (time(NULL));
        int effectiveness = std::rand() % 2;
        if (effectiveness == 0)
        {
            health -= 10;
            std::cout << "                           You've managed to escape with " << health << " health\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 1)
        {
            health = 0;
            std::cout << "                           The " << enemyName << " managed to capture and kill you\n\n";
            std::cout << "                           Please try again.\n\n";
            system("cls");
            std::cin >> input;
            SceneOneMountain();
        }
        if (effectiveness == 2)
        {
            std::cout << "                           You managed to scathe by with " << health << " health... better be careful next time.\n\n";
            std::cin >> input;
            system("cls");
        }
    }

    if (choice == '2')
    {
        srand (time(NULL));
        int effectiveness = std::rand() % 2;
        if (effectiveness == 0)
        {
            health = 10;
            std::cout << "                           You fought the " << enemyName << " and managed to kill it with " << health << " health remaining.. 'I need to be more careful' you think to yourself\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 1)
        {
            std::cout << "                           You hit the " << enemyName << " with an insanely effective critical strike and managed to escape with " << health << " health remaining.\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 2)
        {
            health -= 20;
            std::cout << "                           The monster was a tough opponent... but you managed to defeat it with " << health << " health remaining.\n\n";
            std::cin >> input;
            system("cls");
        }
    }
}

void SceneOneValley()
{
    system("Color 02");
    srand (time(NULL));
    int enemy = std::rand() % 2;
    if (enemy == 0)
    {
        enemyName = "Goblin";
    }
    else if (enemy == 1)
    {
        enemyName = "Demon";
    }
    else if (enemy == 2)
    {   
        enemyName = "Troll";
    }

    std::cout << "                           You begin to make your way in the direction of the valley.\n\n";
    std::cin.get();
    std::cout << "                           you've always loved the bright green fields and animals that populate this path,\n\n";
    std::cin.get();
    std::cout << "                           and thanfully this path is much quicker and less dangerous... But not entirely safe.\n\n";
    std::cin.get();
    std::cout << "                           midway down the path you spot a " << enemyName << "....\n\n";
    std::cin.get();
    std::cout << "                           you quietly think to yourself what to do, before approaching the " << enemyName << ".\n\n";
    std::cin.get();
    std::cout << "                           The " << enemyName << " spots you and is quickly alerted.\n\n";
    std::cin.get();
    std::cout << "                           Do you wish to fight or run past?\n\n";
    std::cout << "                           1. Run    2. Fight\n\n";
    std::cin >> choice;

    if (choice == '1')
    {
        srand (time(NULL));
        int effectiveness = std::rand() % 2;
        if (effectiveness == 0)
        {
            health -= 15;
            std::cout << "                           You've managed to escape with " << health << " health\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 1)
        {
            health = 0;
            std::cout << "                           The " << enemyName << " managed to capture and kill you\n\n";
            std::cout << "                           Please try again.\n\n";
            std::cin >> input;
            system("cls");
            SceneOneValley();
        }
        if (effectiveness == 2)
        {
            std::cout << "                           You managed to scathe by with " << health << " health... better be careful next time.\n\n";
            std::cin >> input;
            system("cls");
        }
    }

    if (choice == '2')
    {
        srand (time(NULL));
        int effectiveness = std::rand() % 2;
        if (effectiveness == 0)
        {
            health = 20;
            std::cout << "                           You fought the " << enemyName << " and managed to kill it with " << health << " health remaining.. 'I need to be more careful' you think to yourself\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 1)
        {
            std::cout << "                           You hit the " << enemyName << " with an insanely effective critical strike and managed to escape with " << health << " health remaining.\n\n";
            std::cin >> input;
            system("cls");
        }
        if (effectiveness == 2)
        {
            health -= 10;
            std::cout << "                           The monster was a tough opponent... but you managed to defeat it with " << health << " health remaining.\n\n";
            std::cin >> input;
            system("cls");
        }
    }
}

void MarketScene()
{
    system("Color 0E");
    system("cls");
    std::cout << "                           ";
    std::cin >> input;
}