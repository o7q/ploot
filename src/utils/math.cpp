#include "math.hpp"

sf::Color parseHexColor(const std::string &hex)
{
    unsigned int hexValue;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> hexValue;

    sf::Uint8 r = (hexValue >> 24) & 0xFF;
    sf::Uint8 g = (hexValue >> 16) & 0xFF;
    sf::Uint8 b = (hexValue >> 8) & 0xFF;
    sf::Uint8 a = hexValue & 0xFF;

    return sf::Color(r, g, b, a);
}