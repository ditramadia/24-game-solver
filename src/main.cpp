#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "splash.cpp"
#include "menu.cpp"
#include "functions.cpp"
#include "input.cpp"
#include "generate.cpp"
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
    }

    return 0;
}