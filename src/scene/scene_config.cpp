#include "scene_config.hpp"

SceneConfig::SceneConfig(std::string filePath)
{
    this->parentPath = getParentPath(filePath);

    if (!doesFileExist(filePath))
    {
        std::string rawConfig =
            "sceneWidth=" + std::to_string(sceneWidth) + "\n" +
            "sceneHeight=" + std::to_string(sceneHeight) + "\n" +
            "sceneFramerate=" + std::to_string(sceneFramerate) + "\n" +
            "sceneBackgroundColor=" + sceneBackgroundColor + "\n";

        writeFile(filePath, rawConfig);
    }

    std::ifstream file(filePath);

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string rawConfig = buffer.str();

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
        if (configKey == "sceneWidth")
        {
            this->sceneWidth = stoi(configValue);
        }
        else if (configKey == "sceneHeight")
        {
            this->sceneHeight = stoi(configValue);
        }
        else if (configKey == "sceneFramerate")
        {
            this->sceneFramerate = stoi(configValue);
        }
        else if (configKey == "sceneBackgroundColor")
        {
            this->sceneBackgroundColor = configValue;
        }
    }
}