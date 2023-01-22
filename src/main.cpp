#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "splash.cpp"
#include "menu.cpp"
#include "input.cpp"
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

        short option = 0;
        std::vector<std::string> cardStrVec;

        while (option < 1 || option > 3)
        {
            std::cout << "Select option: ";
            std::cin >> option;
        }

        switch (option)
        {
        case 1:
            // Input numbers
            manualInput(&cardStrVec);
            break;
        case 2:
            // Generate numbers
            break;
        case 3:
            running = false;
            exit();
            return 0;
        }

        // Display card input
        for (int i = 0; i < cardStrVec.size(); i++)
        {
            std::cout << cardStrVec[i];
        }

        break;
        exit();
    }

    return 0;
}