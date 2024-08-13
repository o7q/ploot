#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "../utils/file.hpp"
#include "../utils/string.hpp"

class SceneConfig
{
public:
    SceneConfig(std::string);

    std::string parentPath = "";

    int sceneWidth = 512;
    int sceneHeight = 512;
    int sceneFramerate = 60;
    std::string sceneBackgroundColor = "00FF00FF";
};