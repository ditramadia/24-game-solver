double operation(double x, double y, char op)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    default:
        if (y != 0)
        {
            return x / y;
        }
        else
        {
            return -999;
        }
    }
}

double absolute(int x)
{
    if (x < 0)
    {
        return -x;
    }
    else
    {
        return x;
    }
}

std::vector<std::vector<int>> permuteNumbers(std::vector<int> &cardIntVec)
{
    std::vector<std::vector<int>> numbersPermutation;

    if (cardIntVec.size() <= 1)
    {
        return {cardIntVec};
    }

    for (int i = 0; i < cardIntVec.size(); i++)
    {
        std::vector<int> vector(cardIntVec.begin(), cardIntVec.end());
        vector.erase(vector.begin() + i);
        auto ret = permuteNumbers(vector);

        for (int j = 0; j < ret.size(); j++)
        {
            std::vector<int> vector2 = ret[j];
            vector2.insert(vector2.begin(), cardIntVec[i]);

            numbersPermutation.push_back(vector2);
        }
    }

    return numbersPermutation;
}

std::vector<std::string> permuteOperators(std::vector<std::vector<int>> numbersPermutation)
{
    std::vector<std::string> solutions;

    char operators[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int x = 0; x < 24; x++)
                {
                    int num1 = numbersPermutation[x][0];
                    int num2 = numbersPermutation[x][1];
                    int num3 = numbersPermutation[x][2];
                    int num4 = numbersPermutation[x][3];

                    // Permute brackets

                    // (N OP N) OP (N OP N)
                    if (operation(num1, num2, operators[i]) * operation(num3, num4, operators[k]) == 24)
                    {
                        std::string solution = "(" + std::to_string(num1) + operators[i] + std::to_string(num2) + ")" + operators[j] + "(" + std::to_string(num3) + operators[k] + std::to_string(num4) + ")";
                        // std::cout << num1 << operators[i] << num2 << operators[j] << num3 << operators[k] << num4 << std::endl;
                        solutions.push_back(solution);
                    }

                    // ((N OP N) OP N) OP N
                    if (operation(operation(operation(num1, num2, operators[i]), num3, operators[j]), num4, operators[k]) == 24)
                    {
                        std::string solution = "((" + std::to_string(num1) + operators[i] + std::to_string(num2) + ")" + operators[j] + std::to_string(num3) + ")" + operators[k] + std::to_string(num4);
                        solutions.push_back(solution);
                    }

                    // (N OP (N OP N)) OP N
                    if (operation(operation(num1, operation(num2, num3, operators[j]), operators[i]), num4, operators[k]) == 24)
                    {
                        std::string solution = "(" + std::to_string(num1) + operators[i] + "(" + std::to_string(num2) + operators[j] + std::to_string(num3) + "))" + operators[k] + std::to_string(num4);
                        solutions.push_back(solution);
                    }

                    // N OP (N OP (N OP N))
                    if (operation(num1, operation(num2, operation(num3, num4, operators[k]), operators[j]), operators[i]) == 24)
                    {
                        std::string solution = std::to_string(num1) + operators[i] + "(" + std::to_string(num2) + operators[j] + "(" + std::to_string(num3) + operators[k] + std::to_string(num4) + "))";
                        solutions.push_back(solution);
                    }

                    // // N OP ((N OP N) OP N)
                    if (operation(num1, operation(operation(num2, num3, operators[j]), num4, operators[k]), operators[i]) == 24)
                    {
                        std::string solution = std::to_string(num1) + operators[i] + "((" + std::to_string(num2) + operators[j] + std::to_string(num3) + ")" + operators[k] + std::to_string(num4) + ")";
                        solutions.push_back(solution);
                    }
                }
            }
        }
    }

    return solutions;
}

std::vector<std::string> calculation(std::vector<std::string> cardStrVec)
{
    std::vector<std::string> solutions;

    // Get vector of card numbers
    std::vector<int> cardIntVec = str2intVec(cardStrVec);

    // Permute numbers
    std::vector<std::vector<int>> numbersPermutation = permuteNumbers(cardIntVec);

    // Permute operators
    solutions = permuteOperators(numbersPermutation);

    return solutions;
}