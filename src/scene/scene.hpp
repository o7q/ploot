#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "scene_config.hpp"
#include "../sprite/sprite.hpp"
#include "../utils/math.hpp"

class Scene
{
public:
    Scene(SceneConfig &);
    ~Scene();

    void handleInput();
    void handleWindow();

private:
    SceneConfig &config;
    std::vector<SceneSprite *> sceneSprites;

    sf::RenderWindow window;

    int keysPressed = 0;
    int keysPressedPrev = 0;

    bool mouseDown = false;
    bool mouseDownPrev = false;
    bool mouseClicked = false;
    bool mouseInWindow = false;
    sf::Vector2i mousePosition;
    sf::Vector2i mousePositionInitial;

    sf::Vector2i windowPosition;
    sf::Vector2i windowPositionInitial;

    // user
    std::string scene = "example";

    int sceneWidth = 512;
    int sceneHeight = 512;
    int sceneFramerate = 60;
    std::string sceneBackgroundColor = "00FF00FF";
    //
};