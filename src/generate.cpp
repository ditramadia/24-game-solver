std::vector<std::string> generateCard()
{
    std::vector<std::string> cardStrVec;

    srand(time(0));

    for (int i = 0; i < 4; i++)
    {
        int randomNumber = 1 + (rand() % 13);
        cardStrVec.push_back(int2string(randomNumber));
    }

    return cardStrVec;
}