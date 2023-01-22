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

std::string int2string(int number)
{
    switch (number)
    {
    case 1:
        return "A";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;
    case 8:
        return "8";
        break;
    case 9:
        return "9";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "J";
        break;
    case 12:
        return "Q";
        break;
    case 13:
        return "K";
        break;
    }

    return " ";
}

int str2int(std::string cardStr)
{
    if (cardStr == "A")
    {
        return 1;
    }
    else if (cardStr == "2")
    {
        return 2;
    }
    else if (cardStr == "3")
    {
        return 3;
    }
    else if (cardStr == "4")
    {
        return 4;
    }
    else if (cardStr == "5")
    {
        return 5;
    }
    else if (cardStr == "6")
    {
        return 6;
    }
    else if (cardStr == "7")
    {
        return 7;
    }
    else if (cardStr == "8")
    {
        return 8;
    }
    else if (cardStr == "9")
    {
        return 9;
    }
    else if (cardStr == "10")
    {
        return 10;
    }
    else if (cardStr == "J")
    {
        return 11;
    }
    else if (cardStr == "Q")
    {
        return 12;
    }
    else if (cardStr == "K")
    {
        return 13;
    }

    return 0;
}

std::vector<int> str2intVec(std::vector<std::string> cardStrVec)
{
    std::vector<int> cardIntVec;

    for (auto card : cardStrVec)
    {
        cardIntVec.push_back(str2int(card));
    }

    return cardIntVec;
}

void displayCards(std::vector<std::string> cardStrVec)
{
    std::cout << std::endl
              << "                  Your cards are:                  " << std::endl;
    std::cout << "                      ";

    for (auto card : cardStrVec)
    {
        std::cout << card << ' ';
    }
    std::cout << std::endl
              << std::endl;
}