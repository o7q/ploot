#include <iostream>

#include "scene/scene.hpp"
#include "scene/scene_config.hpp"
#include "sprite/sprite.hpp"
#include "utils/file.hpp"
#include "utils/random.hpp"

int main()
{
    Random::init();

    createDirectory("ploot");
    if (!createDirectory("ploot\\scenes"))
    {
        createDirectory("ploot\\scenes\\example");
        SceneSprite example("ploot\\scenes\\example\\example.sprite");
    }

    SceneConfig config("ploot\\ploot.cfg");
    Scene scene(config);

    return 0;
}