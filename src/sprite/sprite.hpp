#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../scene/scene_config.hpp"

class SceneSprite
{
public:
    enum class ShakeMode
    {
        SMOOTH,
        NOISE
    };

    SceneSprite(SceneConfig, std::string);
    SceneSprite(std::string);
    ~SceneSprite();

    void loadSpriteFromFile(std::string);
    void configureSpriteInScene(SceneConfig);

    void shake();
    void update(int, float);
    void draw(sf::RenderWindow &);

    void saveSprite(std::string);

private:
    sf::Texture *spriteTexture = nullptr;
    sf::Sprite sprite;

    sf::Vector2f spritePosition;
    sf::Vector2f spritePositionHome;
    float spriteRotation = 0;
    float spriteShakeTimer = 0;

    sf::Vector2f shakeStartPosition;
    float shakeStartRotation;

    // user
    std::string spriteImagePath = "my_image.png";

    sf::Vector2f spriteUserPosition = sf::Vector2f(0, 0);

    sf::Vector2f spriteUserSize = sf::Vector2f(100, 100);

    ShakeMode spriteShakeMode = ShakeMode::SMOOTH;
    float spriteShakeAmount = 1;
    float spriteShakeKeyComboMultiplier = 1;
    float spriteShakeLength = 400;
    sf::Vector2f spriteShakeRotationMinMax = sf::Vector2f(-2.0f, 2.0f);
    //
};