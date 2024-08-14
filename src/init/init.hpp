#pragma once

#include <iostream>

#include "../scene/scene.hpp"
#include "../scene/scene_config.hpp"
#include "../sprite/sprite.hpp"
#include "../utils/file.hpp"
#include "../utils/random.hpp"
#include "../utils/console.hpp"

#include "../version.hpp"

class Ploot
{
public:
    Ploot(int, char *[]);
    int getStatus();

private:
    void help();

    int returnValue = 0;
};