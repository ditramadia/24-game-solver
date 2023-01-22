int countWords(std::string stringInput)
{
    bool isSpace = true;
    int count = 0;

    for (auto c : stringInput)
    {
        if (isspace(c))
        {
            isSpace = true;
        }
        else
        {
            if (isSpace)
            {
                ++count;
                isSpace = false;
            }
        }
    }

    return count;
}

bool nInputValidation(std::string cardInput)
{
    return countWords(cardInput) == 4;
}

bool cardValidation(std::string cardInput)
{
    std::vector<std::string> cardVec;
    std::istringstream ss(cardInput);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        cardVec.push_back(token);
    }

    for (int i = 0; i < cardVec.size(); i++)
    {
        if (cardVec[i].length() == 1)
        {
            if (!isdigit(cardVec[i][0]))
            {
                if (cardVec[i][0] != 'A' && cardVec[i][0] != 'J' && cardVec[i][0] != 'Q' && cardVec[i][0] != 'K')
                {
                    return false;
                }
            }
            else
            {
                if (cardVec[i][0] == '0' || cardVec[i][0] == '1')
                {
                    return false;
                }
            }
        }
        else
        {
            if (cardVec[i][0] != '1' || cardVec[i][1] != '0')
            {
                return false;
            }
        }
    }

    return true;
}

void manualInput(std::vector<std::string> *cardStrVec)
{
    // Display available input
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

    // Input
    std::string cardInput;
    std::istringstream ss(cardInput);
    std::string token;

    std::cout << "Input your cards: ";
    std::getline(std::cin >> std::ws, cardInput);

    // Input Validation
    while (!nInputValidation(cardInput) || !cardValidation(cardInput))
    {
        std::cout << "Please enter 4 valid cards!" << std::endl;

        std::cout << "Input your cards: ";
        std::getline(std::cin >> std::ws, cardInput);
    }

    // Store cards in a list
    while (std::getline(ss, token, ' '))
    {
        (*cardStrVec).push_back(token);
    }
}