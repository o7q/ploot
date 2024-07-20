#include "file.hpp"

bool createDirectory(std::string directory)
{
    if (!(fs::exists(directory) && fs::is_directory(directory)))
    {
        std::cout << "\"" + directory + "\" does not exist. Creating..." << std::endl;
        fs::create_directory(directory);

        return false;
    }

    return true;
}

void writeFile(const std::string &filePath, const std::string &fileContent)
{
    std::ofstream file(filePath);
    file << fileContent;
    file.close();
}

std::string readFile(const std::string &filePath)
{
    std::ifstream file(filePath);

    if (!file)
    {
        std::cout << "\"" + filePath + "\" was not found!" << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string fileContent = buffer.str();

    return fileContent;
}

bool doesFileExist(std::string filePath)
{
    return fs::exists(filePath);
}