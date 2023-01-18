#include <iostream>

short value(std::string card)
{
    if (card == "A")
    {
        return 1;
    }
    else if (card == "2")
    {
        return 2;
    }
    else if (card == "3")
    {
        return 3;
    }
    else if (card == "4")
    {
        return 4;
    }
    else if (card == "5")
    {
        return 5;
    }
    else if (card == "6")
    {
        return 6;
    }
    else if (card == "7")
    {
        return 7;
    }
    else if (card == "8")
    {
        return 8;
    }
    else if (card == "9")
    {
        return 9;
    }
    else if (card == "10")
    {
        return 10;
    }
    else if (card == "J")
    {
        return 11;
    }
    else if (card == "Q")
    {
        return 12;
    }
    else if (card == "K")
    {
        return 13;
    }
    else
    {
        return 0;
    }
}

short cardInput(std::string card, std::string inputMsg)
{
    while (value(card) == 0)
    {
        std::cout << inputMsg;
        std::cin >> (card);
    }
    return value(card);
}

void manualInput(short *num1, short *num2, short *num3, short *num4)
{
    std::cout << std::endl
              << "Cards:" << std::endl
              << "  -- A    Ace (Value of 1)" << std::endl;
    std::cout << "  -- 2    2" << std::endl;
    std::cout << "  -- 3    3" << std::endl;
    std::cout << "  -- 4    4" << std::endl;
    std::cout << "  -- 5    5" << std::endl;
    std::cout << "  -- 6    6" << std::endl;
    std::cout << "  -- 7    7" << std::endl;
    std::cout << "  -- 8    8" << std::endl;
    std::cout << "  -- 9    9" << std::endl;
    std::cout << "  -- 10   10" << std::endl;
    std::cout << "  -- J    Jack (Value of 11)" << std::endl;
    std::cout << "  -- Q    Queen (Value of 12)" << std::endl;
    std::cout << "  -- K    King (Value of 13)" << std::endl
              << std::endl;

    std::string card1 = "0", card2 = "0", card3 = "0", card4 = "0";

    *num1 = cardInput(card1, "First card: ");
    *num2 = cardInput(card2, "Second card: ");
    *num3 = cardInput(card3, "Third card: ");
    *num4 = cardInput(card4, "Fourth card: ");
}