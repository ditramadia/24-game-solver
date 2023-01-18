#include <iostream>

#include "splash.cpp"
#include "menu.cpp"
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
        short num1, num2, num3, num4;

        while (option < 1 || option > 3)
        {
            std::cout << "Select option: ";
            std::cin >> option;
        }

        switch (option)
        {
        case 1:
            // Input numbers
            break;
        case 2:
            // Generate numbers
            break;
        case 3:
            exit();
        }
    }

    return 0;
}