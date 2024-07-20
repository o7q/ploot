#include "scene.hpp"

Scene::Scene(SceneConfig &config) : config(config)
{
    try
    {
        for (const auto &entry : fs::directory_iterator("ploot\\scenes\\" + config.scene))
        {
            if (entry.is_regular_file() && entry.path().extension() == ".sprite")
            {
                SceneSprite *sceneSprite = new SceneSprite(config, entry.path().string());
                sceneSprites.push_back(sceneSprite);
            }
        }
    }
    catch (const fs::filesystem_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    window.create(sf::VideoMode(config.sceneWidth, config.sceneHeight), "ploot", sf::Style::None);
    window.setFramerateLimit(config.sceneFramerate);

    sf::Clock clock;

    sf::Color bgc = parseHexColor(config.sceneBackgroundColor);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        handleInput();
        handleWindow();

        window.clear(bgc);

        for (SceneSprite *sceneSprite : sceneSprites)
        {
            if (keysPressed != keysPressedPrev)
            {
                sceneSprite->shake();
            }

            sceneSprite->update(keysPressed, dt);
            sceneSprite->draw(window);
        }

        window.display();

        keysPressedPrev = keysPressed;
        keysPressed = 0;
    }
}

Scene::~Scene()
{
    for (SceneSprite *sceneSprite : sceneSprites)
    {
        delete sceneSprite;
    }
    sceneSprites.clear();
}