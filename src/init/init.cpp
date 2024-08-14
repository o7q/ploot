#include "init.hpp"

Ploot::Ploot(int argc, char *argv[])
{
    std::string arg1 = inBound(argc, 1) ? argv[1] : "";
    removeChar(arg1, '"');

    std::string arg2 = inBound(argc, 2) ? argv[2] : "";
    removeChar(arg2, '"');

    if (arg1 == "")
    {
        help();

        returnValue = 1;
        return;
    }

    if (arg1 == "-h" || arg1 == "--help")
    {
        help();
    }
    else if (arg1 == "-c" || arg1 == "--create")
    {
        if (arg2 == "")
        {
            returnValue = 1;
            return;
        }

        createDirectory(arg2);
        createDirectory(arg2 + "\\sprites");
        SceneConfig config(arg2 + "\\" + getFileName(arg2) + ".scene");
        SceneSprite example(arg2 + "\\sprites\\example.sprite");
    }
    else if (arg1 == "-l" || arg1 == "--load")
    {
        if (arg2 == "")
        {
            returnValue = 1;
            return;
        }

        if (doesFileExist(arg2))
        {
            SceneConfig config(arg2);
            Scene scene(config);
        }
    }

    returnValue = 0;
    return;
}

int Ploot::getStatus()
{
    return returnValue;
}

void Ploot::help()
{
    std::cout << "ploot " << VERSION << " help:\n"
                                        "-h, --help          |  displays this help page\n"
                                        "-c, --create <NAME> |  creates a new scene\n"
                                        "-l, --load <PATH>   |  loads a scene from a path\n";

    pause();
}