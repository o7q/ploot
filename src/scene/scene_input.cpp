#include "scene.hpp"

void Scene::handleInput()
{
    for (int key = 0; key < sf::Keyboard::KeyCount; ++key)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key)))
        {
            keysPressed++;
        }
    }

    mouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    mousePosition = sf::Mouse::getPosition();

    if (!mouseDownPrev && mouseDown)
    {
        mouseClicked = true;
    }
    else
    {
        mouseClicked = false;
    }

    if (mousePosition.x > windowPosition.x && mousePosition.y > windowPosition.y &&
        mousePosition.x < windowPosition.x + config.sceneWidth && mousePosition.y < windowPosition.y + config.sceneHeight)
    {
        mouseInWindow = true;
    }
    else
    {
        mouseInWindow = false;
    }

    mouseDownPrev = mouseDown;
}