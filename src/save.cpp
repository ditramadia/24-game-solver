void save(std::vector<std::string> solutions, std::string filename)
{
    std::ofstream file(filename);
    for (auto solution : solutions)
    {
        file << solution << std::endl;
    }
    file << std::endl
         << "Generated using 24 Solver by Ditra Amadia";
    file.close();
    std::cout << "                      3. Exit                      " << std::endl;
    std::cout << "     File has been saved (\"" << filename << "\")    " << std::endl
              << std::endl;
}