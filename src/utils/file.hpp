#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

bool createDirectory(std::string);
void writeFile(const std::string &, const std::string &);
std::string readFile(const std::string &);
std::string getParentPath(const std::string &);
std::string getFileName(const std::string &);
bool doesFileExist(const std::string &);