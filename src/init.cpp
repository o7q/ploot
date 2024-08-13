#include "init.hpp"

int Ploot::init(int argc, char *argv[])
{
    std::string arg1 = inBound(argc, 1) ? argv[1] : "";
    removeChar(arg1, '"');

    std::string arg2 = inBound(argc, 2) ? argv[2] : "";
    removeChar(arg2, '"');

    if (arg1 == "")
    {
        help();
        return 1;
    }

    if (arg1 == "-h" || arg1 == "--help")
    {
        help();
    }
    else if (arg1 == "-c" || arg1 == "--create")
    {
        if (arg2 != "")
        {
            createDirectory(arg2);
            createDirectory(arg2 + "\\sprites");
            SceneConfig config(arg2 + "\\" + getFileName(arg2) + ".scene");
            SceneSprite example(arg2 + "\\sprites\\example.sprite");
        }
    }
    else if (arg1 == "-l" || arg1 == "--load")
    {
        if (arg2 != "")
        {
            if (doesFileExist(arg2))
            {
                SceneConfig config(arg2);
                Scene scene(config);
            }
        }
    }

    return 0;
}

void Ploot::help()
{
    std::cout << "ploot help:\n"
                 "-h, --help          |  displays this help page\n"
                 "-c, --create <NAME> |  creates a new scene\n"
                 "-l, --load <PATH>   |  loads a scene from a path\n";

    pause();
}