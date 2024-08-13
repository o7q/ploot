#include <iostream>

#include "init.hpp"

#include "scene/scene.hpp"
#include "scene/scene_config.hpp"
#include "sprite/sprite.hpp"
#include "utils/file.hpp"
#include "utils/random.hpp"
#include "utils/console.hpp"

int main(int argc, char *argv[])
{
    Random::init();
    int exitStatus = Ploot::init(argc, argv);
    
    return exitStatus;
}