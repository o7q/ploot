#include <cmath>

#include "sprite.hpp"
#include "../utils/random.hpp"

SceneSprite::SceneSprite(SceneConfig sceneConfig, std::string spriteConfigPath)
{
    loadSpriteFromFile(spriteConfigPath);
    configureSpriteInScene(sceneConfig);
}

SceneSprite::SceneSprite(std::string writePath)
{
    // overloaded constructor to create default sprite file
    std::string rawConfig =
        "spriteImagePath=\"" + spriteImagePath + "\"\n" +
        "spritePosition=" + std::to_string(spriteUserPosition.x) + "," + std::to_string(spriteUserPosition.y) + "\n" +
        "\n" +
        "# Set spriteHeight to -1 if you want to preserve the image's aspect ratio\n" +
        "spriteSize=" + std::to_string(spriteUserSize.x) + ",-1\n" +
        "\n" +
        "# Shake modes: smooth, noise\n" +
        "spriteShakeMode=noise\n" +
        "\n" +
        "spriteShakeAmount=" + std::to_string(spriteShakeAmount) + "\n" +
        "spriteShakeKeyComboMultiplier=" + std::to_string(spriteShakeKeyComboMultiplier) + "\n" +
        "spriteShakeLength=" + std::to_string(spriteShakeLength) + "\n" +
        "spriteShakeRotationMinMax=" + std::to_string(spriteShakeRotationMinMax.x) + "," + std::to_string(spriteShakeRotationMinMax.y) + "\n";

    writeFile(writePath, rawConfig);
}

SceneSprite::~SceneSprite()
{
    if (spriteTexture != nullptr)
    {
        delete spriteTexture;
    }
}

void SceneSprite::shake()
{
    spriteShakeTimer = spriteShakeLength;

    if (abs(spritePosition.x - spritePositionHome.x) < 0.1 &&
        abs(spritePosition.y - spritePositionHome.y) < 0.1)
    {
        shakeStartPosition = sf::Vector2f(Random::genFloat(-10.0, 10.0), Random::genFloat(-10.0, 10.0));
    }

    shakeStartRotation = Random::genFloat(spriteShakeRotationMinMax.x, spriteShakeRotationMinMax.y);
}

void SceneSprite::update(int keysPressed, float dt)
{
    if (spriteShakeTimer > 0.0)
    {
        spriteShakeTimer -= (1000 * dt);

        float multiplier = keysPressed * spriteShakeKeyComboMultiplier;
        float damp = spriteShakeLength / (spriteShakeAmount * (multiplier + 1));

        sf::Vector2f shakeMult = sf::Vector2f(1.0f, 1.0f);

        switch (spriteShakeMode)
        {
        case ShakeMode::SMOOTH:
            shakeMult = shakeStartPosition;
            break;
        case ShakeMode::NOISE:
            shakeMult = sf::Vector2f(
                Random::genFloat(-10.0f, 10.0f),
                Random::genFloat(-10.0f, 10.0f));
            break;
        }

        sf::Vector2f shake = sf::Vector2f(
            (spriteShakeTimer * shakeMult.x) / damp,
            (spriteShakeTimer * shakeMult.y) / damp);

        float shakeRot = (spriteShakeTimer * shakeStartRotation) / damp;

        spritePosition.x = spritePositionHome.x + shake.x;
        spritePosition.y = spritePositionHome.y + shake.y;

        spriteRotation = 0 + shakeRot;

        if (spriteShakeTimer <= 0)
        {
            spriteShakeTimer = 0;
            spritePosition.x = spritePositionHome.x;
            spritePosition.y = spritePositionHome.y;
            spriteRotation = 0;
        }
    }

    sprite.setPosition(spritePosition);
    sprite.setRotation(spriteRotation);
}

void SceneSprite::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}