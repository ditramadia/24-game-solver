#include <iostream>

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
            manualInput(&num1, &num2, &num3, &num4);
            break;
        case 2:
            // Generate numbers
            break;
        case 3:
            running = false;
            exit();
            return 0;
        }

        // Display cards
        std::cout << std::endl
                  << "Cards value:" << std::endl;
        std::cout << "   " << num1 << " " << num2 << " " << num3 << " " << num4 << std::endl
                  << std::endl;
        break;
        exit();
    }

    return 0;
}