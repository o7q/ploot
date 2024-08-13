#include "sprite.hpp"

void SceneSprite::loadSpriteFromFile(std::string spriteConfigPath)
{
    std::string rawConfig = readFile(spriteConfigPath);

    std::vector<std::string> config = splitString(rawConfig, '\n');

    for (std::string configLine : config)
    {
        std::vector<std::string> configPair = splitString(configLine, '=');

        if (configPair.size() < 2)
        {
            continue;
        }

        std::string configKey = configPair[0];
        std::string configValue = configPair[1];

        removeChar(configValue, '"');
        if (configKey == "spriteImagePath")
        {
            std::string spriteImagePathRaw = configValue;
            fs::path imagePath(configValue);
            fs::path spritePath(spriteConfigPath);
            std::string localPath = spritePath.parent_path().string() + "\\" + imagePath.filename().string();

            if (!doesFileExist(spriteImagePathRaw) && doesFileExist(localPath))
            {
                spriteImagePathRaw = localPath;
            }
            this->spriteImagePath = spriteImagePathRaw;
        }
        else if (configKey == "spritePosition")
        {
            std::vector<std::string> spritePositionRaw = splitString(configValue, ',');
            this->spriteUserPosition.x = stof(spritePositionRaw[0]);
            this->spriteUserPosition.y = stof(spritePositionRaw[1]);
        }
        else if (configKey == "spriteCenter")
        {
            this->centerSprite = configValue == "true";
        }
        else if (configKey == "spriteSize")
        {
            std::vector<std::string> spriteSizeRaw = splitString(configValue, ',');
            this->spriteUserSize.x = stof(spriteSizeRaw[0]);
            this->spriteUserSize.y = stof(spriteSizeRaw[1]);
        }
        else if (configKey == "spriteShakeMode")
        {
            if (configValue == "smooth")
            {
                this->spriteShakeMode = ShakeMode::SMOOTH;
            }
            else if (configValue == "noise")
            {
                this->spriteShakeMode = ShakeMode::NOISE;
            }
        }
        else if (configKey == "spriteShakeAmount")
        {
            this->spriteShakeAmount = stof(configValue);
        }
        else if (configKey == "spriteShakeKeyComboMultiplier")
        {
            this->spriteShakeKeyComboMultiplier = stof(configValue);
        }
        else if (configKey == "spriteShakeLength")
        {
            this->spriteShakeLength = stof(configValue);
        }
        else if (configKey == "spriteShakeRotationMinMax")
        {
            std::vector<std::string> spriteRotationMinMaxRaw = splitString(configValue, ',');
            this->spriteShakeRotationMinMax.x = stof(spriteRotationMinMaxRaw[0]);
            this->spriteShakeRotationMinMax.y = stof(spriteRotationMinMaxRaw[1]);
        }
    }
}

void SceneSprite::configureSpriteInScene(SceneConfig sceneConfig)
{
    spriteTexture = new sf::Texture();
    if (!spriteTexture->loadFromFile(spriteImagePath))
    {
        std::cout << "\"" + spriteImagePath + "\" was not found!" << std::endl;
    }
    sprite.setTexture(*spriteTexture);

    sf::Vector2u textureSize = spriteTexture->getSize();

    float aspect = static_cast<float>(textureSize.x) / static_cast<float>(textureSize.y);
    float sizeX = spriteUserSize.x;
    float sizeY = spriteUserSize.y < 0 ? spriteUserSize.x / aspect : spriteUserSize.y;

    sprite.setScale(sizeX / textureSize.x, sizeY / textureSize.y);
    //sprite.setOrigin(sizeX / 2.0, sizeY / 2.0);

    float positionX = centerSprite ? sceneConfig.sceneWidth / 2 - sizeX / 2 : spriteUserPosition.x;
    float positionY = centerSprite ? sceneConfig.sceneHeight / 2 - sizeY / 2 : spriteUserPosition.y;

    spritePositionHome = sf::Vector2f(
        positionX,
        positionY);

    spritePosition = spritePositionHome;
    spriteRotation = 0;
}