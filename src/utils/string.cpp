#include "string.hpp"

std::vector<std::string> splitString(std::string input, char character)
{
    std::stringstream inputStream(input);
    std::string seg;
    std::vector<std::string> seglist;

    while (std::getline(inputStream, seg, character))
    {
        seglist.push_back(seg);
    }

    return seglist;
}

void removeChar(std::string &input, char character)
{
    input.erase(std::remove(input.begin(), input.end(), character), input.end());
}