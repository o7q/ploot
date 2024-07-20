#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool createDirectory(std::string);
void writeFile(const std::string &, const std::string &);
std::string readFile(const std::string &);
bool doesFileExist(std::string);