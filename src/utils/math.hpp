#pragma once

#include <iostream>
#include <sstream>

#include <SFML/Graphics.hpp>

sf::Color parseHexColor(const std::string &);
bool inBound(int, int);