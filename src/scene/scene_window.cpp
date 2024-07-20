#include "scene.hpp"

void Scene::handleWindow()
{
    windowPosition = window.getPosition();

    if (mouseClicked)
    {
        windowPositionInitial = window.getPosition();
        mousePositionInitial = sf::Mouse::getPosition();
    }

    if (mouseDown && mouseInWindow)
    {
        sf::Vector2i newPos = windowPositionInitial + mousePosition - mousePositionInitial;
        window.setPosition(newPos);
    }
}