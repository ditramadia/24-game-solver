#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

#include "splash.cpp"
#include "menu.cpp"
#include "functions.cpp"
#include "input.cpp"
#include "generate.cpp"
#include "calculation.cpp"
#include "save.cpp"
#include "exit.cpp"

int main()
{
    bool running = true;

    // Display splash screen
    splash();

    while (running)
    {
        // Menu
        menu();

        int option = 0;

        while (option < 1 || option > 3)
        {
            std::cout << "Select option: ";
            std::cin >> option;
        }

        std::vector<std::string> cardStrVec;

        switch (option)
        {
        case 1:
        { // Input numbers
            cardStrVec = manualInput();

            // Display cards
            displayCards(cardStrVec);

            break;
        }
        case 2:
        { // Generate numbers
            int generateOption = 2;

            while (generateOption == 2)
            {
                cardStrVec = generateCard();

                // Display cards
                displayCards(cardStrVec);

                generateMenu();

                std::cout << "Select option: ";
                std::cin >> generateOption;
            }

            break;
        }
        case 3:
        {
            running = false;
            exit();
            return 0;
        }
        }

        // Solutions
        std::vector<std::string> solutions = calculation(cardStrVec);

        // Display solutions
        std::cout << solutions.size() << " solutions found:" << std::endl;
        for (auto solution : solutions)
        {
            std::cout << "  -- " << solution << std::endl;
        }
        std::cout << std::endl;

        // Save menu
        int saveOption = 0;

        while (saveOption < 1 || saveOption > 3)
        {
            saveMenu();

            std::cout << "Select option: ";
            std::cin >> saveOption;
            std::cout << std::endl;
        }

        switch (saveOption)
        {
        case 1:
        { // Save
            std::string filename = "../test/" + cardStrVec[0] + "_" + cardStrVec[1] + "_" + cardStrVec[2] + "_" + cardStrVec[3] + ".txt";
            save(solutions, filename);

            break;
        }
        case 2:
        {
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            running = false;
            exit();
            return 0;
        }
        }
    }

    return 0;
}